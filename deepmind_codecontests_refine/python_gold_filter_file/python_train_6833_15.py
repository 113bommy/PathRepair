a,b=map(int,input().split())
l=[2**i for i in range(1,100)]
t=0
for i in l:
    if a<i:
        t=i
        break
if b==1:
    print(a)
else:
    print(t-1)
