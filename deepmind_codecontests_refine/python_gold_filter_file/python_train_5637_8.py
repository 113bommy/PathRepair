from collections import defaultdict
n = int(input())
arr = list(map(int,input().split()))
arr.sort()
cnt = defaultdict(int)
for i in range(n-1):
    for j in range(i+1,n):
        cnt[ arr[i]+arr[j] ] += 1
print( max(cnt.values()) )