#include "anthroponym.h"

// person1 < person2
int LastnameComparer(Anthroponym person1, Anthroponym person2)
{
    size_t n1_lastname = strlen(person1.lastName);
    size_t n2_lastname = strlen(person2.lastName);
    if (n1_lastname == n2_lastname)
    {
        for (size_t i = 0; i < n1_lastname; i++)
        {
            if (person1.lastName[i] < person2.lastName[i])
                return 1;
            else if (person1.lastName[i] > person2.lastName[i])
                return 0;
        }
        return 0;
    }
    else
    {
        if (n1_lastname < n2_lastname)
        {
            for (size_t i = 0; i < n1_lastname; i++)
            {
                if (person1.lastName[i] < person2.lastName[i])
                    return 1;
                else if (person1.lastName[i] > person2.lastName[i])
                    return 0;
            }
            return 1;
        }
        else
        {
            for (size_t i = 0; i < n2_lastname; i++)
            {
                if (person1.lastName[i] < person2.lastName[i])
                    return 1;
                else if (person1.lastName[i] > person2.lastName[i])
                    return 0;
            }
            return 0;
        }
    }
}
