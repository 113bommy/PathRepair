a=int(input())
h=[]
for i in range(0,a):
    res=0
    x=int(input())
    if x%2==0:
        res=(x/2)-1
    else:
        res=int(x//2)
    h.append(res)
print(*h,sep='\n')