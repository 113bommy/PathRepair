t = int(input())
for i in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    if n < 10:
        print(0,0,0)
        continue
    a.sort(reverse=True)
    g = 0
    s = 0
    b = 0
    mx = max(a)
    for i in range(n//2):
        if a[i] == mx:
            g += 1
        elif g > s:
            s += 1
        elif g < s and a[i] != t:
            b += 1
        
            
        elif g == s and s != 0:
            t = a[i]
            s += 1
        elif g < s and a[i] == t:
            s += 1
    if a[(n//2)] == a[n//2-1]:
        h = a[:n//2].count(a[n//2])
        b -= h
    if b<g or s<g or min(b,g,s) == 0:
        print(0,0,0)
    else:
        print(g,s,b)
            
        