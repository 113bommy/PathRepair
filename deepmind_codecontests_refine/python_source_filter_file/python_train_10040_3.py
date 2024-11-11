n,m = map(int, input().split())
a = list(map(int, input().split()))
c=1
x=0
for i in a:
    if x+i < m:
        x+=i 
    else:
        c+=1
        x=i
    
        
print(c)
    