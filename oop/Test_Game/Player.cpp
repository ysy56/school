#include "Player.h"

Player::Player(){
    x_ = 20;
    y_ = 15;
}

void Player::Move(int x, int y){
    x_ = x_ + x;
    y_ = y_ + y;
}
