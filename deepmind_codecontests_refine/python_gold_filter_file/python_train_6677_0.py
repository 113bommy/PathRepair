import sys

q = int(input())

for num in range(q):
    arr = list(map(int,input().split()))
    
    r = arr[0]*arr[1]

    if arr[0]%2 == 0:
        r2 = int((arr[0]/2)*arr[2] )
    else:
        r2 = int(((arr[0]-1)/2)*arr[2] + arr[1])
    print(min(r,r2))

