a=int(input())
b=int(input())
if b==min(a,b):
    a,b=b,a
c=(a+b)
d=c-a
e=b-c
s=0
p=0
for i in range (1,d+1):
    s=s+i
for j in range (1,e+1):
    p=p+j
print(s+p)