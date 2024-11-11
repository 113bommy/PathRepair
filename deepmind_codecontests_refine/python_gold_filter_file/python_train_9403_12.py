n,k=map(int,input().split(' '))
arr=list(map(int,input().split(' ')))
kth=arr[k-1]
count=0
if(not any(arr)):
    print(count)
else:
    for i in arr:
        if(i>=kth and i!=0):
            count+=1
    print(count)