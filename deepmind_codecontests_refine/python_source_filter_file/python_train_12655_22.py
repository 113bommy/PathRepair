n,k = input().split()
n,k = int(n),int(k)
a = input()
A = []
x = 0
for i in a.split():
    A.append(int(i))
if n == 1:
    print(0)
    A[0] = k
    print(1)
else:
    if A[0]+A[1]<k:
        x = k - A[0] - A[1]
        A[1] = k-A[0]
    
    for j in range(1,n-1):
        if A[j]+A[j+1]>=k:
            continue
        else:
            x = x+k-A[j]-A[j+1]
            A[j+1] = k-A[j]
    if A[-2]+A[-1]<k:
        x = x+k-A[-2]-A[-1]
        A[-1] = 5-A[-2]
    print(x)
    s = ''
    for l in A:
        s = s+str(l)+' '
    print(s)
    
        
    