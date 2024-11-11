a,b,c=map(int,input().split())
g=0
while a<=b:
    if c%a==0:
       g=g+1
    a=a+1
print(g)
