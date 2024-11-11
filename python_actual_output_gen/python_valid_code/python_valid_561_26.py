t = int(input())
for xx in range(t):
    n = int(input())
    s = input()
    l = -1
    r = -1
    control = 0
    for i in range(n-1):
        if(s[i] != s[i+1]):
            l = i 
            r = i+1
            break
    print(l+1, r+1)