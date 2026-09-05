#pragma once
#include "displayapp/apps/Apps.h"
#include "displayapp/screens/Screen.h"
#include "displayapp/Controllers.h"

namespace Pinetime {
  namespace Applications {
    namespace Screens {

      class ActivityApp : public Screen {
        public:
          ActivityApp();
          ~ActivityApp() override;

        private:
          lv_obj_t* textLabel;
          lv_obj_t* actionButton;
          
          // This tells the watch what to do when the button is clicked
          static void ButtonEventHandler(lv_obj_t* obj, lv_event_t event);
          void PickRandomActivity();
      };
    }

    // This registers your app so the watch menu knows what icon to use
    template <>
    struct AppTraits<Apps::ActivityApp> {
      static constexpr Apps app = Apps::ActivityApp;
      static constexpr const char* icon = "\uF04B"; // Just a standard play icon
      static Screens::Screen* Create(AppControllers& controllers) {
        return new Screens::ActivityApp();
      }
    };
  }
}
