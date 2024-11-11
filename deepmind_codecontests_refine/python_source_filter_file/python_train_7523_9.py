import math
#for _ in range(int(input())):
    
    
n = int(input())
a = list(map(int,input().split()))
x = 0
f = {}
f[0] = 1
ans = 0
for i in range(n):

    x+= a[i]
    if x not in f:
        f[x] = 1
    else:
        #f[x]+= 1
        ans += 1
        f ={}
        f[0] = 1
        #x = a[i]
        f[x] = 1

print(ans)


    

