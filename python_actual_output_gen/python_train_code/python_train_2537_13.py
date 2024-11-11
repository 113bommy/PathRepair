n,b,d=map(int,input().split())
a=[int(x) for x in input().split()]
c=0
total=0
for i in a:
    if(i<=b):
        total+=1
    if(total>d):
        total=0
        c+=1
print(c)