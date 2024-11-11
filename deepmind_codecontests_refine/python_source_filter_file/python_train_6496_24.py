m,n=[int(m) for m in input().split()]
lst=list(map(int,input().strip().split()))[:n]
count=0
lst.insert(0,1)
for i in range(0,len(lst)-1):
    if lst[i+1]>=lst[i]:
       count=count+lst[i+1]-lst[i]
    else:
        count=count+4-lst[i]+lst[i+1]
print(count)