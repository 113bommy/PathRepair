t = int(input())

for i in range(t):
    c = 0
    n = int(input())
    l = list(map(int,input().split(' ')))
    for j in range(n):
        for k in range(l[j],2*n+1,l[j]):
            a = k - j
            if (a>=0 and a < n and l[a]*l[j] == a + j + 2):
                c += 1
    print(c)