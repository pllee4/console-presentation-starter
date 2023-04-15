/*
 * params.hpp
 *
 * Created on: Apr 15, 2023 14:01
 * Description:
 *
 * Copyright (c) 2023 Pin Loon Lee (pllee4)
 */

#ifndef PARAMS_HPP
#define PARAMS_HPP

#include "ftxui/dom/elements.hpp"

namespace pllee4 {
namespace Params {
static auto center_aligned =
    ftxui::FlexboxConfig()
        .Set(ftxui::FlexboxConfig::JustifyContent::Center)
        .Set(ftxui::FlexboxConfig::AlignContent::Center);

static auto end_aligned =
    ftxui::FlexboxConfig()
        .Set(ftxui::FlexboxConfig::JustifyContent::FlexEnd)
        .Set(ftxui::FlexboxConfig::AlignContent::FlexEnd);

static int space_bottom = 1;

static auto copyright = "(c) 2023 Pin Loon Lee (pllee4)";

};  // namespace Params
}  // namespace pllee4
#endif /* PARAMS_HPP */
