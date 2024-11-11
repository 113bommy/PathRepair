N = int(input())

ba = 0
_a = 0
b_ = 0
ans = 0
for _ in range(N):
    s = input()
    ans += s.count('AB')
    if s[-1] == 'A' and s[0] == 'B':
        ba += 1
    elif s[-1] == 'A':
        _a += 1
    elif s[0] == 'B':
        b_ += 1

if _a == b_ == 0 and ba > 0:
    ans = ba - 1
else:
    ans += min(ba+_a, ba+b_)

print(ans)
