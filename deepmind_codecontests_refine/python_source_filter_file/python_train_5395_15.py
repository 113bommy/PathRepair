n=int(input())
b=[3*5*7, 3*5*9, 3*5*11, 27*7, 3*5*13]
print(b)
a=0
for i in range(len(b)):
    if b[i]<=n:
        a+=1
print(a)
