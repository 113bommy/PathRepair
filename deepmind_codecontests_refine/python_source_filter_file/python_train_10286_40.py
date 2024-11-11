n=int(input())
a+=list(map(int,input().split()))
for i in range(n-1):
  if a[i]!=i+1:
    c+=1
print("YES" if c<3 else "NO")
  
