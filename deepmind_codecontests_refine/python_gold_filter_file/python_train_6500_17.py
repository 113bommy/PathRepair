import sys
f = sys.stdin.readline
n = int(f().strip())
arr = [int(v) for v in f().strip().split()]
sarr = sorted(arr)
for i in range(1,n):
    arr[i] += arr[i-1]
    sarr[i] += sarr[i-1]
m = int(f().strip())
while m>0:
    t, l, r = map(int, f().strip().split())
    if t==2:
        print(sarr[r-1] - (sarr[l-2] if l-2>=0  else 0))
    else:
        print(arr[r-1] - (arr[l-2] if l-2>=0  else 0))
    m -= 1