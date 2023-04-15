/*
 * console_presentation_starter.cpp
 *
 * Created on: Apr 15, 2023 13:57
 * Description:
 *
 * Copyright (c) 2023 Pin Loon Lee (pllee4)
 */

#include <memory>
#include <string>

#include "ftxui/component/component.hpp"           // for Horizontal, Renderer
#include "ftxui/component/screen_interactive.hpp"  // for ScreenInteractive
#include "params.hpp"

using namespace ftxui;
using namespace pllee4;

int main(int argc, const char* argv[]) {
  auto main_component = Renderer([] {
    return flexbox(
        {
            vbox({hbox({text("WELCOME") | bgcolor(Color::DarkGreen),
                        text(" to my presentation"), text("!") | blink})}),
        },
        Params::center_aligned);
  });

  const auto slide_pages = Renderer(
      [] { return flexbox({focus(text("1/1"))}, Params::end_aligned); });

  const auto copyright = Renderer(
      [] { return flexbox({text(Params::copyright)}, Params::end_aligned); });

  const auto footer = Container::Horizontal({copyright, slide_pages});

  main_component =
      ResizableSplitBottom(Renderer([&footer] { return footer->Render(); }),
                           main_component, &Params::space_bottom);

  auto screen = ScreenInteractive::Fullscreen();
  screen.Loop(main_component);
  return 0;
}