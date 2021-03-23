#include "mainwin.h"
#include <iostream> // for std::cerr logging

Mainwin::Mainwin() : nim{nullptr} {

    // /////////////////
    // G U I   S E T U P
    // /////////////////

    set_default_size(400, 200);
    set_title("SMART");

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

    //         N E W   SCHOOL
    // Append New to the File menu
    Gtk::MenuItem *menuitem_new = Gtk::manage(new Gtk::MenuItem("_New School", true));
    menuitem_new->signal_activate().connect([this] {this->on_new_school_click();});
    filemenu->append(*menuitem_new);

    //         Q U I T
    // Append Quit to the File menu
    Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    menuitem_quit->signal_activate().connect([this] {this->on_quit_click();});
    filemenu->append(*menuitem_quit);

    //     INSERT
    Gtk::MenuItem *menuitem_insert = Gtk::manage(new Gtk::MenuItem("_Insert", true));
    menubar->append(*menuitem_insert);
    Gtk::Menu *insertmenu = Gtk::manage(new Gtk::Menu());
    menuitem_insert->set_submenu(*insertmenu);

    //          New Student
    Gtk::MenuItem *menuitem_student = Gtk::manage(new Gtk::MenuItem("_New Student", true));
    menuitem_student->signal_activate().connect([this] {this->on_new_student_click();});
    insertmenu->append(*menuitem_student);

    //           New Parent
    Gtk::MenuItem *menuitem_parent = Gtk::manage(new Gtk::MenuItem("_New Parent", true));
    menuitem_parent->signal_activate().connect([this] {this->on_new_parent_click();});
    insertmenu->append(*menuitem_parent);

    //           A B O U T
    // Append About to the Help menu
    Gtk::MenuItem *menuitem_about = Gtk::manage(new Gtk::MenuItem("_About", true));
    menuitem_about->signal_activate().connect([this] {this->on_about_click();});
    insertmenu->append(*menuitem_about);
    
    //         Relate

    Gtk::MenuItem *menuitem_relate = Gtk::manage(new Gtk::MenuItem("_Relate", true));
    menubar->append(*menuitem_relate);
    Gtk::Menu *relatemenu = Gtk::manage(new Gtk::Menu());
    menuitem_relate->set_submenu(*relatemenu);

    //         Student to Parent
    Gtk::MenuItem *menuitem_student_parent = Gtk::manage(new Gtk::MenuItem("_Student to     
    Parent", true));
    menuitem_student_parent->signal_activate().connect([this] {this-    
    >on_student_parent_click();});
    relatemenu->append(*menuitem_student_parent);

    // ///////////// //////////////////////////////////////////////////////////
    // T O O L B A R
    // Add a toolbar to the vertical box below the menu
    Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
    vbox->pack_start(*toolbar, Gtk::PACK_SHRINK, 0);
    // vbox->add(*toolbar);

    //     Q U I T
    // Push the quit botton all the way to the right by setting set_expand true
    Gtk::SeparatorToolItem *sep = Gtk::manage(new Gtk::SeparatorToolItem());
    sep->set_expand(true);
    toolbar->append(*sep);

    // /////////////////////////// ////////////////////////////////////////////
    // S T I C K S   D I S P L A Y
    // Provide a text entry box to show the remaining sticks
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

void Mainwin::on_new_student_click()
{

}

void Mainwin::on_new_parent_click()
{

}

void Mainwin::on_student_parent_click()
{

}

void Mainwin::on_about_click() {
    Gtk::AboutDialog dialog;
    dialog.set_transient_for(*this); // Avoid the discouraging warning
    dialog.set_program_name("SMART");
    dialog.set_license_type(Gtk::License::LICENSE_GPL_3_0);
    std::vector< Glib::ustring > artists = {
        "Code for Person, Student, and Parent by https://www.gnu.org/, licensed for personal and commercial purposes with attribution https://www.gnu.org/licenses/gpl-3.0.en.html"};
    dialog.set_artists(artists);
    dialog.run();
}

void Mainwin::on_quit_click() {
    close();
}
