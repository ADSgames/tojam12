/**
 * MENU
 * A.D.S. Games
 * 06/05/2017
**/
#ifndef MENU_H
#define MENU_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#include "keyListener.h"
#include "joystickListener.h"
#include "tools.h"
#include "state.h"
#include "button.h"


//MFW Allan names his enums
enum{
  menu_button_play,
  menu_button_exit,
  menu_button_edit,
  menu_button_help,
};

// Menu
class menu : public state{
  public:
    menu();
    virtual ~menu();

    void update();
    void draw();

  private:

    static const int BUTTON_COUNT = 4;
    button menu_buttons[BUTTON_COUNT];
    // Images
    ALLEGRO_BITMAP *title;
    ALLEGRO_BITMAP *play;
    ALLEGRO_BITMAP *prompt_image;
    ALLEGRO_BITMAP *play_images[50];
    ALLEGRO_BITMAP *title_images[170];
    ALLEGRO_FONT *menu_font;

    int counter_title;
    int counter_play;
    bool counter_prompt;
};

#endif // MENU_H
