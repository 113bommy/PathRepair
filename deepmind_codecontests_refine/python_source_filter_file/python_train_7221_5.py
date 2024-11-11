for f1 in range(5) :
    s = input().split(' ')
    for f2 in range(5) :
        if s[f2] == '1' :
            print(abs(3-f1) +abs(3-f2))
