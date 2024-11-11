n= int(input())
upodds = 0
downodds = 0
flag = False
for _ in range(n):
    x,y = [int(x) for x in input().split()]
    c = 0    
    if x%2!=0:
        upodds+=1
        c+=1
    if y%2!=0:
        downodds+=1
        c+=1
    if c==1:
        flag=True
if upodds%2==0 and downodds%2==0:
    print(0)
elif upodds%2!=0 and downodds%2!=0 and n>1 and flag:
    print(1)
else:
    print(-1)
