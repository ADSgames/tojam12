#ifndef BUTTON_H
#define BUTTON_H

#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>

#include <string>
#include <mouseListener.h>
#include <tools.h>


class button{
  public:
    // Constructor
    button( int x, int y, std::string text, ALLEGRO_FONT *button_font, int width = 10, int height = 10, int padding_x = 10, int padding_y = 10);

    button();
    ~button();

    // Getters
    int getX(){ return x; }
    int getY(){ return y; }

    // Silly Allan! You gotta return padding times two, because there's two sides of padding
    // I gotchu tho, fixed up and respaced buttons in the menu. No weird hitboxes
    // I wonder if you'll ever see this or I'm typing in vain, pretty much my entire life summed up
    int getWidth(){ return width + padding_x * 2; }
    int getHeight(){ return height + padding_y * 2; }
    int getPaddingX(){ return padding_x; }
    int getPaddingY(){ return padding_y; }
    std::string getText(){ return text; }

    void setVisibility( bool newVisible){ visible = newVisible; }
    void toggleVisibility();

    // Setters
    void setPosition( int x, int y){ this -> x = x; this -> y = y; }
    void setSize( int width, int height){ this -> width = width; this -> height = height;}
    void setPadding( int padding_x, int padding_y){ this -> padding_x = padding_x; this -> padding_y = padding_y; }
    void setText( std::string text){ this -> text = text; }
    void setImage( ALLEGRO_BITMAP *image);
    void setFont( ALLEGRO_FONT *font);

    bool mouseReleased();
    bool hover();
    bool clicked();
    void update();

    // Draw
    void draw();
  protected:

  private:
    // Variables
    int x;
    int y;
    int width;
    int height;
    int padding_x;
    int padding_y;

    bool hovering;
    bool old_mouse_down;
    bool mouse_released;

    // Inactive cannot be clicked/hovered
    // Invisible cannot be seen
    // Disabled is both
    bool visible;
    bool active;

    ALLEGRO_BITMAP *image;

    // Font
    ALLEGRO_FONT *button_font;

    std::string text;
};

#endif // BUTTON_H
