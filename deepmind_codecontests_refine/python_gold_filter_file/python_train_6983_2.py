N = int(input())
a = [map(int,input().split()) for i in range(N)]
arr = [[[0 for i3 in range(10)] for i2 in range(3)] for i1 in range(4)]
for b,f,r,v in a:
    arr[b-1][f-1][r-1] += v
i=1
for bl in arr:
    for fl in bl:
        print(' '+' '.join(map(str,fl)))
    if i != len(arr):
        print('#'*20)
    i += 1