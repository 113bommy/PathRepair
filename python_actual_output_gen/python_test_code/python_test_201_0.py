n,m=map(int,input().strip().split())
arr=[]
v=0
for k in range(m):
    list1=list(map(int,input().strip().split()))
    list1=list1[1:]
    if list1==[]:
        v+=1
    else:    
        arr.append(set(list1))
i=0  
while i<len(arr):
    flag=True
    for j in arr[i+1:]:
        if arr[i]&j:
            arr[i]|=j
            arr.remove(j)
            flag=False
            break
    if flag:    
        i+=1    
if len(arr)==0:
    print(v)
else:
    print(v+len(arr)-1)
            