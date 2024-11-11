# coding: utf-8
# Your code here!

a = list(map(int,input().split()))

b = list(map(int,input().split()))

k = [0]*a[2]
pp = 0
su = 0

for i in b:
    for j in range(a[2]):
        if j >= i - a[1]  + 1 and j <= i + a[1] :
                k[j] += 1
            
for i in range(a[2]):
    if k[i] == 0:
        su += 1
        
print(su)

