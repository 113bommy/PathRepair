N = int(input())
arr = list(map(int, input().split()))
r=N
for i in sorted(arr):
    if r>i:r-= 1
    else:r=max(r+1,i-1)
print(r)
