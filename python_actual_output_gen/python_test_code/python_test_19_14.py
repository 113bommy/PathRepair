n,k = map(int,input().split())
l1 = list(map(int,input().split()))
try:
    for i in range(1,len(l1),2):
        if k!=0:
            if l1[i-1]<l1[i] and l1[i]>l1[i+1]:
                l1[i]-=1
                k-=1
except:
    pass
for i in l1:
    print(i,end =' ')