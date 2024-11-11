n, t = map(int, input().split())
arr = list(map(int, input().split()))
ok = False
idx = 1
while idx < len(arr):
    idx = idx + arr[idx - 1]
    if idx == t:ok = True
print("YES" if ok else "NO" )