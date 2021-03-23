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
    // Create a Help menu and add to the menu bar
    Gtk::MenuItem *menuitem_insert = Gtk::manage(new Gtk::MenuItem("_Insert", true));
    menubar->append(*menuitem_insert);
    Gtk::Menu *insertmenu = Gtk::manage(new Gtk::Menu());
    menuitem_insert->set_submenu(*insertmenu);

    //          New Student
    // Append Rules to the Help menu
    Gtk::MenuItem *menuitem_student = Gtk::manage(new Gtk::MenuItem("_New Student", true));
    menuitem_student->signal_activate().connect([this] {this->on_new_student_click();});
    insertmenu->append(*menuitem_student);

    //           New Parent
    // Append Rules to the Help menu
    Gtk::MenuItem *menuitem_parent = Gtk::manage(new Gtk::MenuItem("_New Parent", true));
    menuitem_parent->signal_activate().connect([this] {this->on_new_parent_click();});
    insertmenu->append(*menuitem_parent);

    //           A B O U T
    // Append About to the Help menu
    Gtk::MenuItem *menuitem_about = Gtk::manage(new Gtk::MenuItem("_About", true));
    menuitem_about->signal_activate().connect([this] {this->on_about_click();});
    insertmenu->append(*menuitem_about);

    // ///////////// //////////////////////////////////////////////////////////
    // T O O L B A R
    // Add a toolbar to the vertical box below the menu
    Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
    vbox->pack_start(*toolbar, Gtk::PACK_SHRINK, 0);
    // vbox->add(*toolbar);

    //     N E W   G A M E
    // Add a new game icon
    Gtk::ToolButton *new_game_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::NEW));
    new_game_button->set_tooltip_markup("Create a new game, discarding any in progress");
    new_game_button->signal_clicked().connect([this] {this->on_new_game_click();});
    toolbar->append(*new_game_button);

    //     O N E   S T I C K
    // Add an icon for taking one stick
    Gtk::Image* button1_image = Gtk::manage(new Gtk::Image{"button1.png"});
    button1 = Gtk::manage(new Gtk::ToolButton(*button1_image));
    button1->set_tooltip_markup("Select one stick");
    button1->signal_clicked().connect([this] {this->on_button_click(1);});
    toolbar->append(*button1);

    //     T W O   S T I C K S
    // Add an icon for taking two sticks
    Gtk::Image* button2_image = Gtk::manage(new Gtk::Image{"button2.png"});
    button2 = Gtk::manage(new Gtk::ToolButton(*button2_image));
    button2->set_tooltip_markup("Select two sticks");
    button2->signal_clicked().connect([this] {this->on_button_click(2);});
    toolbar->append(*button2);

    //     T H R E E   S T I C K S
    // Add an icon for taking three sticks
    Gtk::Image* button3_image = Gtk::manage(new Gtk::Image{"button3.png"});
    button3 = Gtk::manage(new Gtk::ToolButton(*button3_image));
    button3->set_tooltip_markup("Select three sticks");
    button3->signal_clicked().connect([this] {this->on_button_click(3);});
    toolbar->append(*button3);

    //     C O M P U T E R   P L A Y E R
    // Add a little space between the 3 stick buttons and computer player
    Gtk::SeparatorToolItem *sep1 = Gtk::manage(new Gtk::SeparatorToolItem());
    toolbar->append(*sep1);

    // Add a toggle button to enable computer to play as Player 2
    Gtk::Image *robot_image = Gtk::manage(new Gtk::Image{"freepik_robot.png"});
    computer_player = Gtk::manage(new Gtk::ToggleToolButton(*robot_image));
    computer_player->set_tooltip_markup("Enable for computer to be Player 2");
    computer_player->signal_clicked().connect([this] {this->on_computer_player_click();});
    toolbar->append(*computer_player);

    //     Q U I T
    // Push the quit botton all the way to the right by setting set_expand true
    Gtk::SeparatorToolItem *sep = Gtk::manage(new Gtk::SeparatorToolItem());
    sep->set_expand(true);
    toolbar->append(*sep);

    // /////////////////////////// ////////////////////////////////////////////
    // S T I C K S   D I S P L A Y
    // Provide a text entry box to show the remaining sticks
    sticks = Gtk::manage(new Gtk::Label());
    sticks->set_hexpand(true);
    sticks->set_vexpand(true);
    vbox->add(*sticks);

    // S T A T U S   B A R   D I S P L A Y ////////////////////////////////////
    // Provide a status bar for game messages
    msg = Gtk::manage(new Gtk::Label());
    msg->set_hexpand(true);
    vbox->pack_start(*msg, Gtk::PACK_SHRINK, 0);
    // vbox->add(*msg);

    // Make the box and everything in it visible
    vbox->show_all();

    // Start a new game
    on_new_game_click();
}

Mainwin::~Mainwin() { }

// /////////////////
// C A L L B A C K S
// /////////////////

// COMBINED observer / callback
void Mainwin::on_button_click(int button) {
    try {
        // Catch the "impossible" out of sticks exception
        nim->take_sticks(button);
        set_sticks();
    } catch(std::exception& e) {
        sticks->set_markup("<b>FAIL:</b> " + std::string{e.what()} + ", start new game");
    }
}

void Mainwin::on_computer_player_click() {
    set_sticks();
}

void Mainwin::on_new_game_click() {
    delete nim;
    nim = new Nim();
    set_sticks();
}

void Mainwin::on_quit_click() {
    close();
}

void Mainwin::on_about_click() {
    Gtk::AboutDialog dialog;
    dialog.set_transient_for(*this); // Avoid the discouraging warning
    dialog.set_program_name("SMART");
    dialog.set_license_type(Gtk::License::LICENSE_GPL_3_0);
    dialog.set_authors(authors);
    std::vector< Glib::ustring > artists = {
        "Code for Person, Student, and Parent by https://www.gnu.org/, licensed for personal and commercial purposes with attribution https://www.gnu.org/licenses/gpl-3.0.en.html"};
    dialog.set_artists(artists);
    dialog.run();
}
