x=[]
for i in range(3):
    x.append(list(map(int,input().split())))
k,l=sum(x[0]),sum(x[2])
if k<l:
    p = (l-k)//2
    i = (l-3*p)//2
    x[0][0] = i+2*p
    x[1][1] = i+p
    x[2][2] = i
elif k==l:
    x[0][0] = x[1][1] = x[2][2] = k//2
else:
    p = (k-l)//2
    i = (k-3*p)//2
    x[0][0] = i
    x[1][1] = i+p
    x[2][2] = i+2*p
for i in range(3):
    print(*x[i])