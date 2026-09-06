#include "displayapp/screens/ActivityApp.h"
#include <cstdlib> // Used for generating random numbers

using namespace Pinetime::Applications::Screens;

// 1. A simple list of activities to pull from
const char* activities[] = {
  "Go for a walk!",
  "Do dot art",
  "Draw",
  "(-_-)",
  "give someone a hug",
  "clean.",
  "balence",
  "Read a book!",
  "Play some football",
  "Clean your desk!"
};
const int totalActivities = 10;

ActivityApp::ActivityApp() {
  // 2. Create the Text Box at the top
  textLabel = lv_label_create(lv_scr_act(), nullptr);
  lv_label_set_text(textLabel, "Tap to remove bordum");
  lv_label_set_align(textLabel, LV_LABEL_ALIGN_CENTER);
  lv_obj_align(textLabel, lv_scr_act(), LV_ALIGN_IN_TOP_MID, 0, 40);

  // 3. Create the Clickable Button at the bottom
  actionButton = lv_btn_create(lv_scr_act(), nullptr);
  lv_obj_set_size(actionButton, 160, 50); // Make it wide enough to tap easily
  lv_obj_align(actionButton, lv_scr_act(), LV_ALIGN_IN_BOTTOM_MID, 0, -40);
  
  // Attach the event handler to the button
  lv_obj_set_user_data(actionButton, this);
  lv_obj_set_event_cb(actionButton, ButtonEventHandler);

  // 4. Put text inside the button
  lv_obj_t* btnLabel = lv_label_create(actionButton, nullptr);
  lv_label_set_text(btnLabel, "ROLL");
}

// 5. This listens for a touch tap event
void ActivityApp::ButtonEventHandler(lv_obj_t* obj, lv_event_t event) {
  if (event == LV_EVENT_CLICKED) {
    auto* app = static_cast<ActivityApp*>(lv_obj_get_user_data(obj));
    app->PickRandomActivity();
  }
}

// 6. The engine that chooses the activity
void ActivityApp::PickRandomActivity() {
  int randomIndex = rand() % totalActivities; // Pick a number between 0 and 5
  lv_label_set_text(textLabel, activities[randomIndex]); // Update the screen!
}

// 7. Clean up memory if the user exits the app
ActivityApp::~ActivityApp() {
  lv_obj_clean(lv_scr_act()); // Wipes the screen components safely
}
