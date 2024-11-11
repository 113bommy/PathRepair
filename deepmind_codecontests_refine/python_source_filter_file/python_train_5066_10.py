k=list(map(int, input().split()))
n=k[0]
m=k[1]
r=list(map(int, input().split()))
#print(r)
a=[r[0]]
for i in range(1,len(r)):
    a.append(r[i]+a[i-1])
#print(a)
def bina(k):
    start=0
    end=len(a)-1
    ans=len(a)-1
    while(start<=end):
        mid=(start+end)//2
        if a[mid]<=k:
            start=mid+1
        else:
            ans=mid
            end=mid-1
    return ans
j=list(map(int, input().split()))
print('aaaaa',bina(37))
for v in j:
    l=bina(v)
   # print(l,v)
    if l!=0:
        print(l+1,v-a[l-1])
    if l==0:
        print(l+1,v)
