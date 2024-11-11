n=int(input())
x=int(1000009)
mark=[True]*x
r={4}
for i in range(2,n):
    if mark[i]:
        for j in range (i*i,x,i):
            mark[j]=False
        r.add(i*i)
for j in map(int,input().split()):
    if j in r:
        print("YES")
    else:
        print("NO")
