t = int(input())
for test in range(t):
    n = int(input())
    s = 1
    a = 1
    i = 0
    while a*2 <= n:
        a = a*2
        s += a
    #print(s)
    print(int(n*(n+1)//2)-s-s)
