#include <ctrcommon/app.hpp>
#include <ctrcommon/gpu.hpp>
#include <ctrcommon/input.hpp>
#include <ctrcommon/platform.hpp>
#include <ctrcommon/ui.hpp>

#include <sys/dirent.h>
#include <sys/errno.h>
#include <stdio.h>
#include <string.h>

#include <sstream>

using namespace std;

int main(int argc, char **argv) {
  if(!platformInit()) {
  }

  bool exit = false;

  auto onLoop = [&]() {

    bool breakLoop = false;

    if(inputIsPressed(BUTTON_A)) {
      //Apply patch
      breakLoop = true;
    }

    if(inputIsPressed(BUTTON_B)) {
      //Exit
      exit = true;
      breakLoop = true;
    }

    std::stringstream stream;
    stream << "A - Spoof eshop and exit" << "\n";
    stream << "B - Exit" << "\n";

    string str = stream.str();
    const string title = "YGW Eshop Spoofer v0.1.0";
    gputDrawString(title, (gpuGetViewportWidth() - gputGetStringWidth(title, 2)) / 2, (gpuGetViewportHeight() - gputGetStringHeight(title, 2) + gputGetStringHeight(str)) / 2, 2);
    gputDrawString(str, (gpuGetViewportWidth() - gputGetStringWidth(str)) / 2, 4);

    return breakLoop;
  };

  while(platformIsRunning()) {
    if(exit){
      break;
    }
    return onLoop();
  }

  platformCleanup();

  return 0;
}
