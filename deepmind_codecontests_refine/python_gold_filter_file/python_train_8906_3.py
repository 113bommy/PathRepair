n=int(input())
a,b,c=2,1,0
while a<=n:
    a,b=a+b,a
    c+=1
print(c)