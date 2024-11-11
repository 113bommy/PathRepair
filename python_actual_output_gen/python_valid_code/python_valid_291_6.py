n = int(input())
l = []
for i in range(n):
    a,b,c = map(str,input().split())
    b = int(b)
    c = int(c)
    l.append([a,b,c])
ans = 0
for i in range(1,366):
    p=q=0
    for j in range(n):
        x,y,z = l[j]
        if y<=i<=z:
            if x=='M':
                p+=1
            else:
                q+=1
    ans = max(ans,min(p,q))
print(ans)