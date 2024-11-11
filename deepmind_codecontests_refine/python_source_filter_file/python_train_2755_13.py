n=int(input())
l=list(map(int,input().split()))
mini=float('inf')
toremove=-1
for i in range(1,n-1):
    if((l[i]-l[i-1])+(l[i+1]-l[i])<mini):
        mini=(l[i]-l[i-1])+(l[i+1]-l[i])
        toremove=i
l.pop(toremove)
print(l)
maxi=float('-inf')
for i in range(n-2):
    if(l[i+1]-l[i]>maxi):
        maxi=l[i+1]-l[i]
print(maxi)
    
