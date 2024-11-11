n=int(input())
a,b=2,1
c=0
while a<=n:
    a,b=a+b,a
    c+=1
print(c)