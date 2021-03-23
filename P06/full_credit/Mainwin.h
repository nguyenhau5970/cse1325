#ifndef __MAINWIN_H
#define __MAINWIN_H

#include <gtkmm.h>
#include <vector>

class Mainwin : public Gtk::Window {
    public:
        Mainwin();
        virtual ~Mainwin();
    protected:
        void on_new_school_click();        // Clear vectors, update display
        void on_new_student_click();       // Obtain namee, email, grade, instance student class, add to vector
        void on_new_parent_click();        // Same as student but its parent
        void on_student_parent_click();    // Reelate student to parent
        void on_about_click();             // Display About dialog
        void on_quit_click();              // Exit the game
    private:
        std::vector<Student> students;
        std::vector<Parent> parents;
        show_data();

        Gtk::Label *display;                         // Status message display
       
};
#endif 
