n = int(input())
a=0
p=0
for i in range(n):
    a+=i
    
    
    if a == n:
        p=1
        print("YES")
        break
    
if p==0:
    print("NO")