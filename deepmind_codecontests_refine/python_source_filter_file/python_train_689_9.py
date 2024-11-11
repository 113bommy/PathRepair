n,d = map(int,input().split())
a = list(map(int,input().split()))
a.sort()
ans = 0
for i in range(0,n):
    for j in range(i,n):
      if(a[j] - a[i] <= d):
        ans = max(ans, j-i+1)
        print(ans)

        
print(n-ans)        

        
