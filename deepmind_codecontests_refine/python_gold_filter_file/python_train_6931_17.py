from math import sqrt
n= int(input())+1
a=int(sqrt(n))+1
k=1
t = [1] * (n-1)
for i in range(2,a):
    for j in range(i*i , n+1 , i ):
        t[j-2],k=2 , 2 
print(k)
print(*t)
    