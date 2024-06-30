#include "source.h"
#include "console.h"

using namespace std;

int main()
{
	System CMD;
	CMD.Width_PowerShell = 120; //Input your width of power shell
	CMD.Height_PowerShell = 30; //Input your height of power shell
	BoardGame input;
	Player user1, user2;

	Input(CMD, input, header, 6, 12, user1, user2);
	StandardMode(CMD, input, header, user1, user2, 6);
	
	return 0;
}