int main()
{
    int x = 3;
    
    while (x > 1)
    {
        if (x % 2 == 0)
        {
            x = x / 2;
        }
        else
        {
            x = 3 * x + 1;
        }
    }
}
