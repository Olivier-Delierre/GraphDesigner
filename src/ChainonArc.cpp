#include "../include/ChainonArc.h"

ChainonArc::ChainonArc(Arc* arc , ChainonArc* succ , Sommet* j) : d_info{*arc} , d_suivant {succ} , d_successeur{j}
{

}
