#ifndef SOCIALNETWORK_H
#define SOCIALNETWORK_H
#include <string.h>
typedef struct SocialNetwork {
	char VKlink[20];
	char TGlink[20];
} SocialNetwork;

void ClearSocialNetwork(SocialNetwork *SocialNetworkArg);

#endif