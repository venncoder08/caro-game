#include "source.h"
#include "console.h"

using namespace std;

int main()
{
	System CMD;
	CMD.Width_PowerShell = 120; //Input your width of power shell
	CMD.Height_PowerShell = 30; //Input your height of power shell

	StandardMode(CMD, 6);

	return 0;
}