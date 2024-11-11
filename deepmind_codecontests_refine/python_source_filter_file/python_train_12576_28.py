N = int(input())
ans = 0
_A = 0
B_ = 0
B_A = 0

for _ in range(N):
    s = input()
    ans += s.count('AB')

    if s[-1] == 'A':
        _A += 1

    if s[0] == 'B':
        B_ += 1

    if s[0] == 'B' and s[-1] == 'A':
        B_A += 1

ans += min(_A, B_)
# if _A == B_ == B_A:
#     ans -= 1
print(ans)
