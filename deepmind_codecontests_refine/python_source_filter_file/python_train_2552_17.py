import math
n= int(input(""))
a= input("").split(" ")
b= []
for i in range(n):
    b.append(int(a[i]))
a= []
for i in range(n):
    ma= max(b)
    j= 0
    for z in range(n):
        if b[z]==ma:
            b[z]= 0
            j+=1
    for k in range(j):
        a.append(ma)
for i in range(n-1):
    if a[i]==a[i+1] | a[i]<=a[i+1]:
        a[i+1]= a[i]-1
s= 0
for i in range(n):
    if a[i]>0:
        s+= a[i]
print(s)
