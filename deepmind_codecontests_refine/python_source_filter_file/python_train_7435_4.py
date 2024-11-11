import math
n=int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
c=int(0)
for i in range(n):
    if a[i]== 1:
        c-=1
    elif a[i]*2 < b[i]:
        c-=1
    else:
        if b[i]%2 == 0:
            c+=int((b[i]/2)**2)
        else:
            c+=int((int(math.ceil(b[i]/2)))*(int(math.floor(b[i]/2))))
print(c)