n = int(input())
t = [0 for i in range(n)]
for i in range(n-1):
    c,s,f = map(int,input().split())
    for j in range(i+1):
        if t[j] <= s:
            t[j] = c + s
        elif t[j] % f:
            t[j] += c
        else:
            t[j] += f - (t[j] % f) + c
for i in t:
    print(i)