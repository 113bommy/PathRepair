from math import ceil
n = int(input())

m = ceil((n+1)/2)
print(m)
for i in range(1,m+1):
    print(1,i)
for i in range(2,m+1):
    if i+m-1 > n:
        break
    print(i,m)
