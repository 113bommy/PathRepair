import math
n=int(input())
a=list(map(int,input().split()))
a.sort()
a.insert(0,0)
s=0
print(a)
for i in range(len(a)-1,-1,-2):
    s=s+math.pi*(a[i]**2-a[i-1]**2)
    #print(i,s)
    if i<=2:
        break
print(s)
            