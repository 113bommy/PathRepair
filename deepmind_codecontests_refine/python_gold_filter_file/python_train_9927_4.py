n = int(input())
arr = [int(item) for item in input().split(' ')]

s_arr = [item for item in sorted(arr)]

mismatch = []
for i in range(n):
    if arr[i] != s_arr[i]:
        mismatch.append((arr[i], i))

print("YES") if len(mismatch) <= 2 else print("NO")
