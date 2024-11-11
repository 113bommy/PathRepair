n,b,d=[int(ele) for ele in input().split()]
l=[int(el) for el in input().split()]
count,sum=0,0
for e in l:
    if e>b:continue
    sum+=e
    if sum>d:
        sum-=d
        count+=1
print(count)