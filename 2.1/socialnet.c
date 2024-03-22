#include "socialnet.h"
void ClearSocialNetwork(SocialNetwork *SocialNetworkArg)
{
	memset(SocialNetworkArg->VKlink, ' ', 20);
	memset(SocialNetworkArg->TGlink, ' ', 20);
}