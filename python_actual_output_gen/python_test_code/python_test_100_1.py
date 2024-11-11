N,M = map(int,input().split())
A = [int(x) for x in input().split()]
A.sort()
B = [int(x) for x in input().split()]
for i in B:
    #Binary Search for i in A
    low = 0
    high = N-1
    while(low<=high):
        mid = (low + high)>>1
        if(low==high):
            if(A[low]==i):
                print(low+1,end = " ")
            else:
                print(low,end = " ") #Doubt
            break
        else:
            if(A[mid]>i):
                high = mid
            else:
                low = mid + 1
        
        
        