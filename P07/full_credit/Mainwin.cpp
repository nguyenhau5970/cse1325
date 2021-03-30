#include "mainwin.h"
#include "entrydialog.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

const int MAX_STUDENTS = 100;
const int MAX_PARENTS = 400;

Mainwin::Mainwin() {

    students.reserve(MAX_STUDENTS);
    parents.reserve(MAX_PARENTS);

    // /////////////////
    // G U I   S E T U P
    // /////////////////

    set_default_size(400, 200);
    set_title("untitled.smart");

    // Put a vertical box container as the Window contents
    Gtk::Box *vbox = Gtk::manage(new Gtk::VBox);
    add(*vbox);

    // /////// ////////////////////////////////////////////////////////////////
    // M E N U
    // Add a menu bar as the top item in the vertical box
    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar);
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);
    // vbox->add(*menubar);

    //     F I L E
    // Create a File menu and add to the menu bar
    Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);

    //         N E W   S C H O O L
    // Append New to the File menu
    Gtk::MenuItem *menuitem_new = Gtk::manage(new Gtk::MenuItem("_New School", true));
    menuitem_new->signal_activate().connect([this] {this->on_new_school_click();});
    filemenu->append(*menuitem_new);

    //        SAVE
    //
    Gtk::MenuItem *menuitem_new = Gtk::manage(new Gtk::MenuItem("_Save", true));
    menuitem_new->signal_activate().connect([this] {this->on_save_click();});
    filemenu->append(*menuitem_new);

    //        SAVE AS
    //
    Gtk::MenuItem *menuitem_new = Gtk::manage(new Gtk::MenuItem("_Save As", true));
    menuitem_new->signal_activate().connect([this] {this->on_save_as_click();});
    filemenu->append(*menuitem_new);

    //        OPEN
    //
    Gtk::MenuItem *menuitem_new = Gtk::manage(new Gtk::MenuItem("_Open", true));
    menuitem_new->signal_activate().connect([this] {this->on_open_click();});
    filemenu->append(*menuitem_new);

    //         Q U I T
    // Append Quit to the File menu
    Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    menuitem_quit->signal_activate().connect([this] {this->on_quit_click();});
    filemenu->append(*menuitem_quit);

    //     I N S E R T
    // Create an Insert menu and add to the menu bar
    Gtk::MenuItem *menuitem_insert = Gtk::manage(new Gtk::MenuItem("_Insert", true));
    menubar->append(*menuitem_insert);
    Gtk::Menu *insertmenu = Gtk::manage(new Gtk::Menu());
    menuitem_insert->set_submenu(*insertmenu);

    //         N E W   S T U D E N T
    // Append New Student to the Insert menu
    Gtk::MenuItem *menuitem_new_student = Gtk::manage(new Gtk::MenuItem("New _Student", true));
    menuitem_new_student->signal_activate().connect([this] {this->on_new_student_click();});
    insertmenu->append(*menuitem_new_student);

    //         N E W   P A R E N T
    // Append New Parent to the Insert menu
    Gtk::MenuItem *menuitem_new_parent = Gtk::manage(new Gtk::MenuItem("New _Parent", true));
    menuitem_new_parent->signal_activate().connect([this] {this->on_new_parent_click();});
    insertmenu->append(*menuitem_new_parent);

    //         T E S T   D A T A
    // Append Test Data to the Insert menu
    Gtk::MenuItem *menuitem_test_data = Gtk::manage(new Gtk::MenuItem("_Test Data", true));
    menuitem_test_data->signal_activate().connect([this] {this->on_easter_egg();});
    insertmenu->append(*menuitem_test_data);

    //     R E L A T E
    // Create a Relate menu and add to the menu bar
    Gtk::MenuItem *menuitem_relate = Gtk::manage(new Gtk::MenuItem("_Relate", true));
    menubar->append(*menuitem_relate);
    Gtk::Menu *relatemenu = Gtk::manage(new Gtk::Menu());
    menuitem_relate->set_submenu(*relatemenu);

    //         S T U D E N T  T O  P A R E N T
    // Append Student to Parent to the Insert menu
    Gtk::MenuItem *menuitem_student_parent = Gtk::manage(new Gtk::MenuItem("_Student to Parent", true));
    menuitem_student_parent->signal_activate().connect([this] {this->on_student_parent_click();});
    relatemenu->append(*menuitem_student_parent);

    //     H E L P
    // Create a Help menu and add to the menu bar
    Gtk::MenuItem *menuitem_help = Gtk::manage(new Gtk::MenuItem("_Help", true));
    menubar->append(*menuitem_help);
    Gtk::Menu *helpmenu = Gtk::manage(new Gtk::Menu());
    menuitem_help->set_submenu(*helpmenu);

    //           A B O U T
    // Append About to the Help menu
    Gtk::MenuItem *menuitem_about = Gtk::manage(new Gtk::MenuItem("_About", true));
    menuitem_about->signal_activate().connect([this] {this->on_about_click();});
    helpmenu->append(*menuitem_about);

     // ///////////// //////////////////////////////////////////////////////////
    // T O O L B A R
    // Add a toolbar to the vertical box below the menu
    Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
    vbox->add(*toolbar);


    //     N E W   S C H O O L
    // Add a new game icon
    Gtk::ToolButton *new_school_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::NEW));
    new_school_button->set_tooltip_markup("Create a new school");
    new_school_button->signal_clicked().connect([this] {this->on_new_school_click();});
    toolbar->append(*new_school_button);

    //     OPEN SCHOOL
    // Add a new game icon
    Gtk::ToolButton *open_school_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::OPEN));
    open_school_button->set_tooltip_markup("Open a different or new school");
    open_school_button->signal_clicked().connect([this] {this->on_open_click();});
    toolbar->append(*open_school_button);

    //     SAVE SCHOOL
    // Add a new game icon
    Gtk::ToolButton *save_school_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::SAVE));
    save_school_button->set_tooltip_markup("Save your current data");
    save_school_button->signal_clicked().connect([this] {this->on_save_click();});
    toolbar->append(*save_school_button);

    //     SAVE SCHOOL AS
    // Add a new game icon
    Gtk::ToolButton *save_school_as_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::SAVE_AS));
    save_school_as_button->set_tooltip_markup("Specify the name and location you want to save");
    save_school_as_button->signal_clicked().connect([this] {this->on_save_as_click();});
    toolbar->append(*save_school_as_button);


    // INSERT ICONS


    //     INSERT STUDENT
    // Add a new game icon
    Gtk::Image* insert_student_image = Gtk::manage(new Gtk::Image{"insert_student.png"});
    insert_student = Gtk::manage(new Gtk::ToolButton(*insert_student_image));
    insert_student->set_tooltip_markup("Insert Student");
    insert_student->signal_clicked().connect([this] {this->on_new_student_click();});
    toolbar->append(*insert_student);

    //     INSERT PARENT
    // Add a new game icon
    Gtk::Image* insert_parent_image = Gtk::manage(new Gtk::Image{"insert_parent.png"});
    insert_parent = Gtk::manage(new Gtk::ToolButton(*insert_parent_image));
    insert_parent->set_tooltip_markup("Insert Parent");
    insert_parent->signal_clicked().connect([this] {this->on_new_parent_click();});
    toolbar->append(*insert_parent);

    //    RELATE STUDENT TO PARENT
    // Add a new game icon
    Gtk::Image* relate_image = Gtk::manage(new Gtk::Image{"relate.png"});
    relate = Gtk::manage(new Gtk::ToolButton(*relate_image));
    relate->set_tooltip_markup("Relate Student to Parent");
    relate->signal_clicked().connect([this] {this->on_student_parent_click();});
    toolbar->append(*relate);


    // /////////////////////////// ////////////////////////////////////////////
    // D I S P L A Y
    // Provide a text entry box to show the data
    display = Gtk::manage(new Gtk::Label());
    display->set_hexpand(true);
    display->set_vexpand(true);
    vbox->add(*display);

    // S T A T U S   B A R   D I S P L A Y ////////////////////////////////////
    // Provide a status bar for game messages
    msg = Gtk::manage(new Gtk::Label());
    msg->set_hexpand(true);
    vbox->pack_start(*msg, Gtk::PACK_SHRINK, 0);
    // vbox->add(*msg);

    // Make the box and everything in it visible
    vbox->show_all();

    // Start a new game
    on_new_school_click();
}

Mainwin::~Mainwin() { }

// /////////////////
// C A L L B A C K S
// /////////////////

void Mainwin::on_new_school_click() {
    students.clear();
    parents.clear();
    show_data();
}

void Mainwin::on_save_click(std::ostream& ost)
{
    
}

void Mainwin::on_save_as_click()
{
    Gtk::FileChooserDialog dialog("Please choose a file",
          Gtk::FileChooserAction::FILE_CHOOSER_ACTION_SAVE);
    dialog.set_transient_for(*this);
    
    auto filter_SMART = Gtk::FileFilter::create();
    filter_nim->set_name("SMART files");
    filter_nim->add_pattern("*.smart");
    dialog.add_filter(filter_SMART);
    
    dialog.set_filename("untitled.smart");
    
    dialog.add_button("_Cancel", 0);
    dialog.add_button("_Save", 1);
    
    int choice = dialog.run;
    
    if (choice == 1) {
        try {
            std::ofstream ofs{dialog.get_filename()};
            smart->save(ofs);
            on_save_click(filename);
        }catch (std::exception& e) {
            Gtk::MessageDialog{*this, "Unable to save"}.run();
        }
    } else {
        return;
    }
}

void Mainwin::on_open_click()
{
    Gtk::FileChooserDialog dialog("Please choose a file",
          Gtk::FileChooserAction::FILE_CHOOSER_ACTION_OPEN);
    dialog.set_transient_for(*this);
    
    auto filter_SMART = Gtk::FileFilter::create();
    filter_nim->set_name("SMART files");
    filter_nim->add_pattern("*.smart");
    dialog.add_filter(filter_SMART);
    
    dialog.set_filename("untitled.smart);
    
    dialog.add_button("_Cancel", 0);
    dialog.add_button("_Save", 1);
    
    int choice = dialog.run;
    
    if (choice == 1) {
        try {
            on_new_school_click();
            std::ifstream ifs{dialog.get_filename()};
            smart = new smart{ifs};
            if(!ifs) throw std::runtime_error{"Bad file contents"};
            show_data();
        }catch (std::exception& e) {
            Gtk::MessageDialog{*this, "Unable to open"}.run();
        }
    } else {
        return;
    }
}

void Mainwin::on_new_student_click() {     // Create a new student
    try {
        EntryDialog name{*this, "Student name?"};
        if(name.run() == Gtk::RESPONSE_OK) name.hide();
        else return;

        EntryDialog email{*this, "Student email?"};
        if(email.run() == Gtk::RESPONSE_OK) email.hide();
        else return;

        int grade = select("Student grade?", 12, 1);
        if(grade < 1) return;

        students.push_back(Student{name.get_text(), email.get_text(), grade});
    } catch(std::exception& e) {
        Gtk::MessageDialog{*this, "Invalid entry!"+std::string{e.what()}}.run();
    }
    show_data();
}
void Mainwin::on_new_parent_click() {      // Create a new parent
    try {
        EntryDialog name{*this, "Parent name?"};
        if(name.run() == Gtk::RESPONSE_OK) name.hide();
        else return;

        EntryDialog email{*this, "Parent email?"};
        if(email.run() == Gtk::RESPONSE_OK) email.hide();
        else return;

        parents.push_back(Parent{name.get_text(), email.get_text()});
    } catch(std::exception& e) {
        Gtk::MessageDialog{*this, e.what()}.run();
    }
    show_data();
}
void Mainwin::on_student_parent_click() {  // Relate student and parent
    try {
        int student = select_student(); if (student < 0) return;
        int parent = select_parent(); if (parent < 0) return;
        students.at(student).add_parent(parents.at(parent));
        parents.at(parent).add_student(students.at(student));
    } catch(std::exception& e) {
        Gtk::MessageDialog{*this, e.what()}.run();
    }
    show_data();
}

void Mainwin::on_quit_click() {
    close();
}


// /////////////////
// U T I L I T I E S
// /////////////////

void Mainwin::show_data() {
    std::string s;
    s += "    Students\n\n";
    for(int i=0; i<students.size(); ++i)
        s += students.at(i).full_info() + '\n';
    s += "\n    Parents\n\n";
    for(int i=0; i<parents.size(); ++i)
        s += parents.at(i).full_info() + '\n';

    display->set_markup(s);
}

// Returns index of selected student, or -1 for Cancel / Close
int Mainwin::select_student() {
    std::string prompt = "Select Student\n\n";
    for(int i=0; i<students.size(); ++i)
        prompt += std::to_string(i) + ") " + students[i].to_string() +'\n';
    return select(prompt, students.size()-1);
}

// Returns index of selected parent, or -1 for Cancel / Close
int Mainwin::select_parent() {
    std::string prompt = "Select Parent\n\n";
    for(int i=0; i<parents.size(); ++i)
        prompt += std::to_string(i) + ") " + parents[i].to_string() +'\n';
    return select(prompt, parents.size()-1);
}

// Returns int between [min, max], or min-1 for Cancel / Close
int Mainwin::select(std::string prompt, int max, int min) {
    int selection = min-1;
    while(true) {
        try {
            EntryDialog dialog{*this, prompt};
            int response = dialog.run();
            if(response == Gtk::RESPONSE_OK) {
                selection = std::stoi(dialog.get_text());
                if (min <= selection && selection <= max) break;
                throw std::out_of_range{"Invalid selection"};
            } else {
                selection = min-1; // Likely Cancel or X
                break;
            }
        } catch(std::exception& e) {
            Gtk::MessageDialog{*this, e.what()}.run();
        }
    }
    return selection;
}

void Mainwin::on_about_click() {
    Gtk::AboutDialog dialog;
    dialog.set_transient_for(*this); // Avoid the discouraging warning
    dialog.set_program_name("SMART Program");
    auto logo = Gdk::Pixbuf::create_from_file("stock-S-symbol.jpg");
    dialog.set_logo(logo);
    dialog.set_copyright("Copyright 2017-2020");
    dialog.set_license_type(Gtk::License::LICENSE_GPL_3_0);
    std::vector< Glib::ustring > authors = {"Nguyen Hau, George F. Rice"};
    dialog.set_authors(authors);
    std::vector< Glib::ustring > artists = {
        "Logos and icons from stuttershock, https://www.shutterstock.com"
    };
    dialog.set_artists(artists);
    dialog.run();
}

void Mainwin::on_easter_egg() {
    const std::vector<std::string> names{
        "Enrique Young",  // student
        "Isabella Young", // student
        "Biniti Adani", // student
        "James Montgomery", //student
        "Robert Young",
        "Susan Young",
        "Nimish Adani",
        "Oscar Montgomery",
      };
    const std::vector<std::string> emails{
        "eyoung@gmale.com",
        "iyoung@fmale.com",
        "biniti@myschool.org",
        "james.q.montgomery@british.uk",
        "bob-young@woohoo.com",
        "youngsr@uta.edu",
        "nimish.adani@hatmail.com",
        "oscar.the.m@funville.net",
      };
    const std::vector<int> grades {
          1, 5, 3, 12, // For students only
      };
    try {
        on_new_school_click();
        for(int i=0; i<grades.size(); ++i)
            students.push_back(Student{names[i], emails[i], grades[i]});
        for(int i=grades.size(); i<names.size(); ++i)
           parents.push_back(Parent{names[i], emails[i]});
        students[0].add_parent(parents[0]); parents[0].add_student(students[0]);
        students[0].add_parent(parents[1]); parents[1].add_student(students[0]);
        students[1].add_parent(parents[0]); parents[0].add_student(students[1]);
        students[1].add_parent(parents[1]); parents[1].add_student(students[1]);
        students[2].add_parent(parents[2]); parents[2].add_student(students[2]);
        students[2].add_parent(parents[1]); parents[1].add_student(students[2]);
        students[3].add_parent(parents[1]); parents[1].add_student(students[3]);
        students[3].add_parent(parents[2]); parents[2].add_student(students[3]);
        students[3].add_parent(parents[3]); parents[3].add_student(students[3]);
        show_data();
    } catch(std::exception& e) {
        Gtk::MessageDialog{*this, e.what()}.run();
    }
}
