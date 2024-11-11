t = int(input())
c = 0
for i in range(t):
    n,s,e = input().split()
    s = int(s)
    e = int(e)
    if (s >= 2400 and e >= 2400):
        if s < e:
            c = 1
if c == 1:
    print("YES")
else:
    print("NO")