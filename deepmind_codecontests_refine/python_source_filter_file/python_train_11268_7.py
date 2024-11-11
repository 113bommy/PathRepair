import math
t=int(input())
while(t>0):
    n = int(input())
    arr = list(map(int,input().strip().split()))
    maxi = int(-2e9)
    val = 0
    two_val=1
    for i in range(len(arr)):
        maxi=max(maxi, arr[i])
        val=max(val, maxi - arr[i])
    step=0
    while(two_val<val):
        two_val = two_val * 2
        step+=1
    print(step)
    t-=1
