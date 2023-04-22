#include "../inc/graine.h"

Graine::Graine(): Utile_elem()
{

}

Graine::~Graine()
{
}

void Graine::showSeed() 
{
    if(nb_pts == 10) 
        set_h(6);
    else 
        set_h(24);
}