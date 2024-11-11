n,s=map(int,input().split())
l=sorted(list(map(int,input().split()))for _ in range(n))[::-1]
t=l[0][0]
pre=0
for i in range(n):
    t+=l[pre][0]-l[i][0]
    pre=i
    if t<l[i][1]: t=l[i][1]
print(t+l[-1][0])