n,m = map(int,input().split())
l = list(map(int,input().split()))
lb = 0
ub = m
for i in range(1,len(l)):
    l[i]=l[i]+l[i-1]
for i in l:
    if i<0:
        lb = max(lb,-i)
    elif i>=0:
        ub = min(ub,m-i)
print(ub-lb+1)        
      
    
    
