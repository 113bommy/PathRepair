n,c,k = map(int,input().split())
t = [int(input()) for i in range(n)]
t.sorted()

pas = 1
last_bus = t[0] + k
ans = 1

for i in t[1:]:
  if i <= last_bus and pas < c:
    pas +=1
  else:
    ans +=1
    pas =1
    last_bus = i + k
    
    
print(ans)
  
  
