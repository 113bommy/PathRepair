k,p = map(int,input().split())
a=[]
nnk = 1
for i in range(k):
    x=str(nnk)+str(nnk)[::-1]
    a.append(int(x))
    nnk+=1
print(sum(a)%p)
