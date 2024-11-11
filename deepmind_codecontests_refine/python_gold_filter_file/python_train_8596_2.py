n,m=map(int,input().split());a=list(map(int,input().split()));b=list(map(int,input().split()))
diff=[];ans=0
for i in range(n):diff.append([a[i]-b[i],i])
diff.sort()
for i in range(m):ans+=a[diff[i][1]]
for j in range(m,n):
    if diff[j][0]<0:ans+=a[diff[j][1]]
    elif diff[j][0]>=0:ans+=b[diff[j][1]]
print(ans)