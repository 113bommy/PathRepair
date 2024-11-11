for i in range(int(input())):
    n = int(input())
    s = ' '+input()
    f = True
    for i in range(1,n+1):
        if f:
            for j in range(i+1,n+1):
                if s[i:j+1].count('a') == s[i:j+1].count('b'):
                    print(i,j)
                    f = False
                    break
        else:
            break
    if f:
        print(-1,-1)