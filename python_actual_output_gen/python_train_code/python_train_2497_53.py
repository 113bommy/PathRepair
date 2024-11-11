
for i in range(5):
    l1=list(map(int,input().split()))
    if(l1.count(1)>0):
        y=l1.index(1)
        x=i
        break
print(abs(x-y))
