def swap(x,y):
    pointer = x[0]
    x[0] = y[n-1]
    y[n-1] = pointer
    x.sort()
    y.sort()
  
    
for _ in [0]*int(input()):
    n,k = list(map(int,input().split()))
    A = sorted(list(map(int,input().split())))
    B = sorted(list(map(int,input().split())))
    for item in range(k):
        
        if A[0]>=B[n-1]:
            break
        else:
            swap(A,B)
            
print(sum(A))