n=int(input())
a=list(map(int,input().split()))
b=a
h=[0]*200005
#for minimum
 
a.sort()
min=1
 
a=list(set(a))
a[0]+=1
for i in range(1,len(a)):
    if a[i]==a[i-1]:
        a[i]=a[i-1]
    elif(a[i]-1==a[i-1]):
        a[i]=a[i-1]
    else:
        min+=1
        a[i]+=1
#for maximum
b.sort()
h[b[0]-1]+=1
h[b[n-1]+1]+=1
for i in range(1,len(b)):
    
    if  h[b[i]-1]==0:
        h[b[i]-1]+=1
    elif h[b[i]]==0:
        h[b[i]]+=1
    elif h[b[i]]!=0 and h[b[i]+1]==0:
        h[b[i]+1]+=1
mx=0
for j in range(len(h)):
    if h[j]!=0:
        mx+=1
if n==1:
    print("1 1")
else:
    print(min,mx)