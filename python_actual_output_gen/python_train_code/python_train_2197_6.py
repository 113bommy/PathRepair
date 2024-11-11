n, k = map(int, input().split())
target = input() + '.'
keys = input().split()

ptr = 0
ans = 0
for pos, key in enumerate(target):
    if key in keys:
        continue
    length = pos - ptr
    ans += (length * (length+1)) // 2
    ptr = pos
print(ans)