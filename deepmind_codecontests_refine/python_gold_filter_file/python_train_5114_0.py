n=int(input())
arr=list(map(int,input().split()))
count=0
for i in range(1,len(arr)-1):
    if arr[i]==0 and arr[i-1]==1 and arr[i+1]==1:
        count+=1
        arr[i+1]=0
print(count)
    
        

    
    
    