import math,time
#t1=time.time()
n=int(input())
#n=2500
ans=0
for i in range(1,n):
    for j in range(i+1,n):
        if i^j<=n:
            ls1=[i,j,i^j]
            ls1.sort()
            if ls1[0]+ls1[1]>ls1[2]:
                #print(ls1)
                ans+=1
print(math.ceil(ans/2))
#print(time.time()-t1)