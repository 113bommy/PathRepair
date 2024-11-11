n = input()

i = 0

left, right = 1, 2 ** len(n) + 1
while i < len(n):
    # print(left, right)
    mid = (left + right) / 2
    if n[i] == "7":
        left = mid
    else:
        right = mid
    i += 1

# print(left, right)
ans = left

for i in range(1, len(n)):
    ans += 2 ** i

print(ans)
