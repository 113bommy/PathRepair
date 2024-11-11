import math
def b_search(l,r,arr,x) :

    while(l<=r) :
        mid = (l+r)//2

        if x<arr[mid] :
        
            r = mid-1 

        
        elif x>arr[mid] :
        
            l = mid+1 
    
        elif x==arr[mid] :
        
            return True 
        
    return False

n = int(input())

N = math.sqrt(2*n)

arr = []
arr.append(0)

for i in range(1,int(N)+1) :
    
    arr.append(arr[i-1]+i)
    
#print(arr)
    
flag = 1
    
for i in range(int(N)) :
    if b_search(0,int(N),arr,n-arr[i]) :
        
        print("YES")
        flag = 0
        break
    
if flag :
    print("NO")

    

    


