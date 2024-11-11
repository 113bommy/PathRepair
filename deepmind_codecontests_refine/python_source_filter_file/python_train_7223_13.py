for _ in range(int(input())):
    s = input()
    n = len(s)
    if s[:5] == 'miao.' and s[n-5:n]=='lala.':
        print("OMG>.< I don't know!")
    else:
        if s[n-5:n] == 'miao.' or s == 'miao.':
            print("Rainbow's")
        elif s[n-5:n] == 'lala.' or s == 'lala.':
            print("Freda's")
        else:
            print("OMG>.< I don't know!")