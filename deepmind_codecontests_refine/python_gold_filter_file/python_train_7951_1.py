from math import sqrt

n=int(input())
count=0
for i in range(1,n+1):
    for j in range(i,n+1):
        c = sqrt(i**2 + j**2)
        if c.is_integer() and c<=n:
            count+=1
print(count)
