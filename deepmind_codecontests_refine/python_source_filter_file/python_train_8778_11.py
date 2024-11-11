k,n=map(int,input().split())
d={}
d1=[]
res=0
for i in range(n):
    a,b=map(int,input().split())
    if b in d:
        d[b]+=a
    else:
        d[b]=a
    d1.append(b)
d1.sort()
d1.reverse()
# print(d)
# print(d1)
for i in d1:
    if k>=d[i]:
        res+=(d[i]*i)
        k-=d[i]
    else:
        res+=(k*i)
        k-=d[i]
    # print(res)
    if k<=0:
        break
print(res)
        
        

    