n=int(input())
arr=[int(x) for x in input().split()]
i=0;j=n-1
d=0
while i<j:
    arr[i]-=d
    arr[j]-=d
    d+=1
    i+=1
    j-=1
if i==j:
    arr[i]-=d
dict={}
for item in arr:
    if item not in dict:
        dict[item]=1
    else:
        dict[item]+=1
m=0
for key,val in dict.items():
    m=max(m,val)
print(n-m)
