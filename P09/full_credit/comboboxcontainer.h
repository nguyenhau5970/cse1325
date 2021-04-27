#ifndef __COMBOBOXCONTAINER_H
#define __COMBOBOXCONTAINER_H

#include <gtkmm.h>
#include <iostream>
#include <sstream>

template <class T>

class ComboBoxContainer : public Gtk::ComboBoxText {
    public:
        ComboBoxContainer(Const T& container, int setActive = 0)
        {
            std::ostringstream oss;

            for (auto c : container)
            {
                oss.str("");
                oss << *c;
            }

        }
}

#endif
