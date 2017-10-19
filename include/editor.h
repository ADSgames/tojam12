/**
 * BOX
 * Allan Legemaate
 * 05/05/2017
**/
#ifndef EDITOR_H
#define EDITOR_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_native_dialog.h>

#include <vector>
#include <string>
#include <math.h>
#include <algorithm>

#include "rapidxml.hpp"
#include "rapidxml_print.hpp"

#include "mouseListener.h"
#include "keyListener.h"
#include "tools.h"
#include "Button.h"
#include "globals.h"
#include "game.h"
#include "UIHandler.h"
#include "CheckBox.h"

#include "state.h"

// Nice editor boxes
struct editor_box{
  float x;
  float y;
  std::string x_str;
  std::string y_str;
  std::string bodyType;
  int type;
  int orientation[4];
  int width;
  int height;
  bool affect_character;
  std::string width_str;
  std::string height_str;
};

// The editor state
class editor : public state{
  public:
    editor();
    virtual ~editor();

    // Override parent
    void update();
    void draw();
  private:

    UIHandler editorUI;
    // Images
    ALLEGRO_BITMAP *image_box[6];
    ALLEGRO_BITMAP *tiles[5][15];

    // Functions
    void calculate_orientation_global();

    bool box_at(int x, int y);
    bool box_at_with_type(int newType,int x, int y);

    bool save_map( std::string mapName);
    bool load_map( std::string mapName);

    static const int BUTTON_COUNT = 17;

    // Tiles
    std::vector<editor_box> editorBoxes;

    // Map name
    const char *file_name;

    bool gui_mode;

    float box_1_x;
    float box_1_y;

    float box_2_x;
    float box_2_y;

    bool is_dragging_box = false;
    bool dialog_open = false;

    // Remember saves
    bool is_saved = false;

    // Vars
    bool grid_on;

    int tile_type;
    int level_number;
    bool test_mode = false;

    // The font
    ALLEGRO_FONT *edit_font;
};

#endif // EDITOR_H
