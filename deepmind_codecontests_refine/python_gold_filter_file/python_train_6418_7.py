n=int(input())
a = [int(t) for t in input().strip().split(' ')]
b=[]
c=[]
for i in range(n):
    if a[i] > 0 :
        b.append(a[i])
    else:
        c.append(a[i])
if(sum(c)==0):
    print(sum(b))
else:
    print(sum(b)-sum(c))
    