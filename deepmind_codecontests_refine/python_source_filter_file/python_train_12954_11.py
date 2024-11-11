n , m  = map(int,input().split())
ans=[]
c=0
if m<n//2:
    print(-1)
    exit()
elif n==1 and m!=0:
    print(-1)
    exit()
elif n==1 and m==0:
    print(0)
    exit()                
m-=(n//2-1)
ans.append((1)*m)
ans.append((2)*m)
k=ans[-1]
for i in range(1,n-2,2):
    ans.append(k+i)
    ans.append(k+i+1)
if n%2!=0:
    ans.append(10**9)   
print(*ans)    