n=int(input())
a,b,c=1,2,0
while a<=n:
    a,b=a+b,a
    c+=1
print(c)