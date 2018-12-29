#pragma once
#include <SDL_image.h>
#include <SDL.h>
#undef main

#include <string>
#include <stdio.h>
#include <vector>
#include <cstdio>
#include <ctime>
#include "Collision.h"
#include "Input.h"
#include "Move.h"
#include "Initialize.h"
#include "Draw.h"

static Initialize initialize;
static Collision collision;
static Input input;
static Move move;
static Draw draw;

constexpr auto Pi = 3.141592;
constexpr auto SCREEN_WIDTH = 640;
constexpr auto SCREEN_HEIGHT = 360;
constexpr auto Friction = .25;
constexpr auto EdgeFriction = .95;