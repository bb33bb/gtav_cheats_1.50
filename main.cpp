#include "cheats.h"

int main(int argc, char* argv[])
{
	gtav_cheats* g = new gtav_cheats();
	g->initialize_gtav();
	g->start_cheats();
	return 0;
}