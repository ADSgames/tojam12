/**
 * UIHandler
 * Danny Van Stemp and Allan Legemaate
 * Manages UI
 * 24/09/2017
 **/

#ifndef UIHANDLER_H
#define UIHANDLER_H

#include <vector>
#include <string>

#include "ui/UIElement.h"

class UIHandler {
  public:
    UIHandler() {};
    virtual ~UIHandler() {};
    void addElement(UIElement *newUIElement);
    void draw();
    void update();
    bool isHovering();

    void createButton(int x, int y,std::string newText,std::string id,ALLEGRO_FONT *newFont);
    void createAnchoredButton(std::string,ALLEGRO_FONT *,std::string,std::string,bool);

    [[deprecated("Look up by ID instead using getElementById")]]
    UIElement* getElementByText(std::string);

    UIElement* getElementById(std::string);

    std::vector<UIElement*> getUIElements();

  private:
    std::vector<UIElement*> ui_elements;
};

#endif // UIHANDLER_H
