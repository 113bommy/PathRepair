x=input().split()
y=input().split()

a=int(x[0])
b=int(x[1])
k=0
c=0
for i in y:
    i=int(i)
    k=b-(86400-i)
    c=c+1
    if k<=0:
        print(c)
        break
