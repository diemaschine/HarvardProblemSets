#define MAX 65536

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    if (value < 0)
    {
        return false;
    }
    
    int end = n - 1;
    int start = 0;
    
    while (end >= start)
    {
        int mid_i = (start+end)/2;
        int mid_v = values[mid_i];
        
        if (mid_v == value)
        {
            return true;
        }
        else if (mid_v > value)
        {
            end = mid_i - 1;
        }
        else if (mid_v < value)
        {
            start = mid_i + 1;
        }
    }
    
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{

    int counting_table[MAX+1] = {0};
    
    for (int i = 0; i < n; i++)
    {
        counting_table[values[i]]++;
    }
    
    int list_index = 0;
    
    for (int i = 0; i < MAX+1; i++)
    {
        for (int j = 0; j < counting_table[i]; j++)
        {
            values[list_index] = i;
            list_index++;
        }
    }
}
