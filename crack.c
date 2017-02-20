#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

#define _XOPEN_SOURCE
#include <unistd.h>

#define SALT "50"
#define ALPHABET "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"

string crack_password(string hash);
char *crypt(const char *key, const char *salt);

int main(int argc, string argv[]) {
    
    if (argc != 2)
    {
        printf("Usage: ./crack hash");
        return 1;
    }
    
    string password = crack_password(argv[1]);
    printf("%s\n", password);
    
}

bool string_comparison(string hash, string current_hash) {
    
    for (int i = 0; hash[i] != '\0'; i++)
    {
        if (hash[i] != current_hash[i])
        {
            return false;
        }
    }
    return true;
}

string sngl_dgt_crkr(string hash)
{
    static char sngl_dgt[] = "a";
    
    int index0 = 0;
    
    while (true)
    {
        if (sngl_dgt[0] != 'Z')
        {
            sngl_dgt[0] = ALPHABET[index0];
            index0++;
        }
        else
        {
            return sngl_dgt;
        }
        
        string curr_hash = crypt(sngl_dgt, SALT);
        
        if (string_comparison(hash, curr_hash))
        {
            return sngl_dgt;
        }
    }
}

string dbl_dgt_crkr(string hash)
{
    static char dbl_dgt[] = "aa";
    
    int index0 = 0;
    int index1 = 0;
    
    while (true)
    {
        if (dbl_dgt[0] != 'Z')
        {
            dbl_dgt[0] = ALPHABET[index0];
            index0++;
        }
        else
        {
            dbl_dgt[0] = 'a';
            index0 = 0;
            if (dbl_dgt[1] != 'Z')
            {
                dbl_dgt[1] = ALPHABET[index1];
                index1++;
            }
            else
            {
                return dbl_dgt;
            }
        }
        
        string curr_hash = crypt(dbl_dgt, SALT);
        
        if (string_comparison(hash, curr_hash))
        {
            return dbl_dgt;
        }
    }
}

string trpl_dgt_crkr(string hash)
{
    static char trpl_dgt[] = "aaa";
    
    int index0 = 0;
    int index1 = 0;
    int index2 = 0;
    
    while (true)
    {
        if (trpl_dgt[0] != 'Z')
        {
            trpl_dgt[0] = ALPHABET[index0];
            index0++;
        }
        else
        {
            trpl_dgt[0] = 'a';
            index0 = 0;
            if (trpl_dgt[1] != 'Z')
            {
                trpl_dgt[1] = ALPHABET[index1];
                index1++;
            }
            else
            {
                trpl_dgt[1] = 'a';
                index1 = 0;
                if (trpl_dgt[2] != 'Z')
                {
                    trpl_dgt[2] = ALPHABET[index2];
                    index2++;
                }
                else
                {
                    return trpl_dgt;
                }
            }
        }
        
        string curr_hash = crypt(trpl_dgt, SALT);
        
        if (string_comparison(hash, curr_hash))
        {
            return trpl_dgt;
        }
    }
}

string quad_dgt_crkr(string hash)
{
    static char quad_dgt[] = "aaaa";
    
    int index0 = 0;
    int index1 = 0;
    int index2 = 0;
    int index3 = 0;
    
    while (true)
    {
        if (quad_dgt[0] != 'Z')
        {
            quad_dgt[0] = ALPHABET[index0];
            index0++;
        }
        else
        {
            quad_dgt[0] = 'a';
            index0 = 0;
            if (quad_dgt[1] != 'Z')
            {
                quad_dgt[1] = ALPHABET[index1];
                index1++;
            }
            else
            {
                quad_dgt[1] = 'a';
                index1 = 0;
                if (quad_dgt[2] != 'Z')
                {
                    quad_dgt[2] = ALPHABET[index2];
                    index2++;
                }
                else
                {
                    quad_dgt[2] = 'a';
                    index2 = 0;
                    if (quad_dgt[3] != 'Z')
                    {
                        quad_dgt[3] = ALPHABET[index3];
                        index3++;
                    }
                    else
                    {
                        return quad_dgt;
                    }
                }
            }
        }
        
        string curr_hash = crypt(quad_dgt, SALT);
        
        if (string_comparison(hash, curr_hash))
        {
            return quad_dgt;
        }
    }
}

string crack_password(string hash)
{
    string password0 = sngl_dgt_crkr(hash);
    string curr_hash = crypt(password0, SALT);
    if (string_comparison(hash, curr_hash))
    {
        return password0;
    }
    
    string password1 = dbl_dgt_crkr(hash);
    curr_hash = crypt(password1, SALT);
    if (string_comparison(hash, curr_hash))
    {
        return password1;
    }
    
    string password2 = trpl_dgt_crkr(hash);
    curr_hash = crypt(password2, SALT);
    if (string_comparison(hash, curr_hash))
    {
        return password2;
    }
    
    string password3 = quad_dgt_crkr(hash);
    curr_hash = crypt(password3, SALT);
    if (string_comparison(hash, curr_hash))
    {
        return password3;
    }
    
    return "Password not found.";
}
