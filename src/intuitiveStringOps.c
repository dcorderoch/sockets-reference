#include "intuitiveStringOps.h"

/* Returns true if the Strings (Char *) pStr1 and pStr2
 * have the same length and the same characters
 *
 * @param pStr1 and pStr2
 * @return boolean
 */
bool equalStrings(char * pStr1, char * pStr2)
{
	bool retVal = true;

	int strlen1 = strlen(pStr1);
	int strlen2 = strlen(pStr2);

	bool stessalen = (strlen1 == strlen2);
	bool equal = (strncmp(pStr1,pStr2,strlen1) == 0);

	if(!stessalen || !equal)
	{
		retVal = false;
	}
	return retVal;
}
