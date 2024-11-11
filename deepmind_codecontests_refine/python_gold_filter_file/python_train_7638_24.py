n, m, d = map(int, input().split())
c = []
for i in range(n):
    l = list(map(int, input().split()))
    c+=l
v = c[0]%d
flag = False
for i in c:
    if i%d != v:
        flag = True
        break
if flag:
    print(-1)
else:
    c.sort()
    median = c[(n*m)//2]
    count = 0
    for i in range(n*m):
        if i<n*m//2:
            count+=abs((median - c[i])//d)
        else:
            count+=abs((c[i]-median))//d
    print(count)
        
