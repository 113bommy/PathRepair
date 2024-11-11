input()
a,b,ans = [0]*6, [0]*6, 0
for i in list(map(int,input().split())):a[i]+=1
for i in list(map(int,input().split())):b[i]+=1
for i in range(1,6):
    if((a[i]+b[i])%2>0):exit(print(-1))
for i in range(1,6):ans+=abs(a[i]-(a[i]+b[i])//2)
print(ans//2)