
for _ in range(int(input())):
    n=int(input())
    if n<9:
        print(0)
    elif n==9:
        print(1)
    else:
        s=str(n)
        if int(s[len(s)-1])==9:
            s=s[0:len(s)-1]
            print(int(s)+1)
        else:
            s=s[0:len(s)-1]
            print(int(s))