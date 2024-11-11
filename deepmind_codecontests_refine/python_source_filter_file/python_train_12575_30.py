N = int(input())
S = input()

ans = 0
left, right = 0, 1

while right < N:
    s = S[left:right]
    if s in S[right:]:
        right += 1
        ans = max(ans, len(s))
    else:
        left = right - 1

print(ans)
