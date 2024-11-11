t=int(input())

for tt in range(t):
    n,k=map(int, input().split())
    arr=list(map(int, input().split()))

    max_val=-float('inf')
    for i in range(max(0,n-201)):
        for j in range(i+1,n):
            max_val=max(max_val, (i+1)*(j+1)-k*(arr[i] | arr[j]))

    print(max_val)