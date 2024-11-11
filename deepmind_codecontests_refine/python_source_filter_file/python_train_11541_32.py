a,b,c = map(int,input().split())
ans = 'No'

for i in range(1,b+1):
  if (a*i)%b == c:
    ans = 'Yes'
    
print(ans)