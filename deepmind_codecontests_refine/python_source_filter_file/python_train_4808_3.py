n=int(input())
a=list(map(int,input().split()))

d={}

for i in range(n):
    d[a[i]]=0

i=0
j=n-1
length = -1
while(i<n):
    if(d[a[i]]==0):
        d[a[i]]=1
        i+=1
    else:
        break

length = max(i,length)

while(j>i):
    if(d[a[j]]==0):
        d[a[j]]=1
        j-=1
    elif(i>0):
        length = max(length,i+n-1-j)
        i-=1
        d[a[i]]=0
    else:
        length = max(i+n-1-j,length)
        break 
print(n-length)