n,d,a = map(int,input().split())
XH = []
for _ in range(n):
    x,h = map(int,input().split())
    h = (h+a-1)//a
    XH.append([x,h])
ans = 0
XH.sort()
p = 0
j = 0
data = []
for i in range(n):
    while XH[i][0] > XH[j][0] + 2*d:
        p -= data[j]
        j += 1
    p_i = min(XH[i][1]-p,0)
    data.append(p_i)
    ans += p_i
    p += p_i

print(ans)