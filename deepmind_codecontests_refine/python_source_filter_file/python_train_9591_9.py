nks=list(map(int,input().split(' ')))
nn=list(map(int,input().split(' ')))
n=nks[0]
k=nks[1]
sum=0
for i in range(0,n):
    sum+=nn[i]
mins=1000
maxs=-1000
for b in range(0,k):
    c=b
    s=0
    while c<n:
        s+=nn[c]
        c+=k
    if s<mins:
        mins=s
    if s>maxs:
        maxs=s
result=max(abs(sum-maxs),abs(sum+mins))
print(result)
