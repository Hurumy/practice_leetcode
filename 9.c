bool isPalindrome(int x) {
    char str[11];
    str[10] = '\0';

    if (x < 0)
        return (false);

    for (int i=0; i<10; i++)
    {
        str[i] = -1;
    }

    for (int i = 1; x != 0; i ++)
    {
        str[10 - i] = x % 10;
        x = x / 10;
    }

    int m = 1;
    for (int i=0; i<10; i++)
    {
        if (str[i] == -1)
            continue;
        else if (i == 10 - m)
            break;
        else
        {
            if (str[i] == str[10 - m])
                m ++;
            else
                return (false);
        }
    }
    return (true);
}
