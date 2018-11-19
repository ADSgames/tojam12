#include "ActionBinder.h"

binding ActionBinder::game_binding[10];


bool ActionBinder::actionPressed(int newAction){

  for(int i=0; i<NUM_BINDABLE_BUTTONS; i++){
    if(keyListener::keyPressed[game_binding[newAction].key_code[i]])
      return true;
    if(joystickListener::stickDirections[game_binding[newAction].stick[i]])
      return true;

     if(joystickListener::buttonPressed[game_binding[newAction].joystick_button[i]])
      return true;
    }
  return false;

}

bool ActionBinder::actionHeld(int newAction){

  for(int i=0; i<NUM_BINDABLE_BUTTONS; i++){
    if(keyListener::key[game_binding[newAction].key_code[i]])
      return true;
    if(joystickListener::stickDirections[game_binding[newAction].stick[i]])
      return true;

    if(joystickListener::button[game_binding[newAction].joystick_button[i]])
      return true;
    }
  return false;

}

void ActionBinder::setDefaults(){
  game_binding[jump].key_code[0] = ALLEGRO_KEY_W;
  game_binding[jump].joystick_button[0] = JOY_XBOX_A;
  game_binding[jump].stick[0] = DPAD_UP;


  game_binding[move_left].key_code[0]=ALLEGRO_KEY_A;
  game_binding[move_left].stick[0] = LEFT_STICK_LEFT;
  game_binding[move_left].stick[1] = DPAD_LEFT;


  game_binding[move_right].key_code[0]=ALLEGRO_KEY_D;
  game_binding[move_right].stick[0] = LEFT_STICK_RIGHT;
  game_binding[move_right].stick[1] = DPAD_RIGHT;


  game_binding[freeze].key_code[0]=ALLEGRO_KEY_SPACE;
  game_binding[freeze].joystick_button[0]=JOY_XBOX_X;
  game_binding[freeze].joystick_button[1]=JOY_XBOX_BUMPER_LEFT;
  game_binding[freeze].joystick_button[2]=JOY_XBOX_BUMPER_RIGHT;

  game_binding[restart].key_code[0] = ALLEGRO_KEY_R;
  game_binding[restart].joystick_button[0] = JOY_XBOX_B;

  game_binding[confirm].key_code[0]=ALLEGRO_KEY_ENTER;
  game_binding[confirm].joystick_button[0]=JOY_XBOX_A;


}

ActionBinder::ActionBinder()
{
  //ctor
}

ActionBinder::~ActionBinder()
{
  //dtor
}