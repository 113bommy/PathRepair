n = int(input())
s = str(input())
t = str(input())
a = sorted(s)
b = sorted(t)
move = []
k = 0
if a == b:
    for i in range(0,n-1):
        if s[i] != t[i]:
            p = s.find(t[i])
            k = k + abs(p-i)
            for q in range(p,i,-1):
                move.append(q)
            s = t[:i+1] + s[i:p] + s[p+1:]
    print(k)
    for e in move:
        print(e,end=' ')
else:
    print(-1)