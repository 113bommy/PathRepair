n=int(input())
if n==1:
    arr=list(map(int,input().split()))
    arr.sort()
elif n==2:
    arr1=list(map(int,input().split()))
    arr2=list(map(int,input().split()))
    arr=[]
    for i in arr1:
        arr.append(i)
    for i in arr2:
        arr.append(i)
    for i in arr1:
        for j in arr2:
            arr.append(i*10+j)
            arr.append(j*10+i)
    arr=list(set(arr))
    arr.sort()
elif n==3:
    arr1=list(map(int,input().split()))
    arr2=list(map(int,input().split()))
    arr3=list(map(int,input().split()))
    arr=[]
    for i in arr1:
        arr.append(i)
    for i in arr2:
        arr.append(i)
    for i in arr3:
        arr.append(i)
    for i in arr1:
        for j in arr2:
            arr.append(i*10+j)
            arr.append(j*10+i)
    for i in arr2:
        for j in arr3:
            arr.append(i*10+j)
            arr.append(j*10+i)
    for i in arr1:
        for j in arr3:
            arr.append(i*10+j)
            arr.append(j*10+i)
    for i in arr1:
        for j in arr2:
            for k in arr3:
                arr.append(i*100+j*10+k)
                arr.append(i*100+k*10+j)
                arr.append(j*100+i*10+k)
                arr.append(j*100+k*10+i)
                arr.append(k*100+i*10+j)
                arr.append(k*100+j*10+i)
    arr=list(set(arr))
    arr.sort()
if arr[0]==0:
    t=0 
else:
    t=1 
flag=0 
for i in range(len(arr)):
    if i+t!=arr[i]:
        flag=1 
        break
#print(arr)
if flag==1:
    print(i-1+t)
else:
    print(i+t)
                
                
    
    