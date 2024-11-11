n=int(input())
arr=[int(item) for item in input().split()]
mini=10**9+1
for j in arr:
    if(j<mini):
        mini=j
i=-1
j=-1
flag=0
count=10**9+1
for k in range(n):
    if(arr[k]==mini and flag==0):
        flag=1
        i=k
        continue
    if(arr[k]==mini and flag==1):
        if(count>k-i):
            count=k-i
            i=k
print(count)    
        
