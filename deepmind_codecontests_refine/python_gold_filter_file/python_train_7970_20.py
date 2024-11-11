n,k = map(int, input().split())
x = 240-k
c = 0
i = 1
while(True and i<=n):
    x -= i*5
    if x>=0:    
        c+=1
    else:
        break
    i+=1
print(c)