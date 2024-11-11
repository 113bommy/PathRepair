n=int(input())
m=[]
for i in range(n):
    l=list(map(int,input().split()))
    m.append(l)
s=[]
for j in range(3):
    sx=0
    for i in range(n):
        sx=sx+m[i][j]
    s.append(sx)
if sum(s)==0:
    print("YES")
else:
    print("NO")