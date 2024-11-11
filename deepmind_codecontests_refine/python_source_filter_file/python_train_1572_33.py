n=int(input())
l=list(map(int,input().split()))
l.sort()
ans=[]
ans.append((l[n-1]-l[0])*(l[2*n-1]-l[n]))
for i in range(n):
    ans.append((l[2*n-1]-l[0])*(l[n+i]-l[i]))
print(min(ans))    