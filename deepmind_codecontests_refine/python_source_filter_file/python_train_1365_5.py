n,d = map(int,input().split())

a=list(map(int,input().split()))

b=list(map(int,input().split()))
ps=[]
cs = a[d-1] +b[0]
b=b[1:]
f=0
a.pop(d-1)
src=[]
j=n-2
i=0
for k in range(n-1):
    if a[k]>=cs :
        src.append(a[k]+b[i]) 
        i+=1 
    else:
        src.append(a[k]+b[j]) 
        j-=1
src.sort(reverse=True)

for j in range(n-1):
    if cs>=src[j]:
        print(j+1)
        f=1
        break 
if f==0:
    print(n)
    

        