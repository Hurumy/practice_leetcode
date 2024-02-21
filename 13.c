
int combineCheck(char *s, int i)
{
    if (s[i] != '\0' && s[i + 1] != '\0')
    {
        char a = s[i];
        char b = s[i + 1];
        if (a == 'I' && b == 'V')
            return (4);
        if (a == 'I' && b == 'X')
            return (9);
        if (a == 'X' && b == 'L')
            return (40);
        if (a == 'X' && b == 'C')
            return (90);
        if (a == 'C' && b == 'D')
            return (400);
        if (a == 'C' && b == 'M')
            return (900);
    }
    return (-1);
}

int romanToInt(char* s) {
    int res = 0;
    char c;
    int com = 0;

    for (int i=0; s[i] != '\0'; i++)
    {
        com = combineCheck(s, i);
        if (com != -1)
        {
            res += com;
            i ++;
            continue;
        }
        else
        {
            c = s[i];
            if (c == 'I')
                res += 1;
            else if (c == 'V')
                res += 5;
            else if (c == 'X')
                res += 10;
            else if (c == 'L')
                res += 50;
            else if (c == 'C')
                res += 100;
            else if (c == 'D')
                res += 500;
            else if (c == 'M')
                res += 1000;
        }
    }
    return (res);
}
