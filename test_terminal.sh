#!/bin/bash

clear_screen="\033[H\033[2J"
cursor_position="\033[5;10H"
cursor_position_group="\033[6;8H"
red_on_black="\033[31;40m"
green_on_white="\033[32;47m"
default_color="\033[0m"
cursor_reset="\033[H\033[10;1H"

echo "${clear_screen}"
echo "${cursor_position}${red_on_black}Константин"
echo "${cursor_position_group}${green_on_white}ИА-232"
echo "${default_color}${cursor_reset}"