import math
n=int(input())
for i in range(n):
    arr=[int(i) for i in input().split()]
    coal=arr[1]*arr[2]
    stick=arr[2]
    torch=coal+stick
    if (torch-1)%(arr[0]-1)==0:
        ans=(torch-1)//(arr[0]-1)
    else:
        ans=(torch-1)//(arr[0]-1)+1
    print(ans+arr[2])
        
    
    
    