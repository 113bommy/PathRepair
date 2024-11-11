import math

def printArr(arr):
    for i in arr:
        print(i,end=" ")
def proA(arr):
    ans=[]
    i=0
    c=0
    while(i<len(arr)):
        if(i==len(arr)-1):
            ans.append(arr[-1])
            break
            
        if(math.gcd(arr[i],arr[i+1])!=1):
            c+=1
            ans.append(arr[i])
            ans.append(1)
            
        else:
            ans.append(arr[i])
        i+=1
    print(c)
    printArr(ans)
    
n=int(input())
arr=list(map(int,input().split()))
proA(arr)