S = input()
n = len(S)
ans = n//2
c = S[ans]

while ans <= n:
    if c == S[ans] == S[-ans-1]:
        ans += 1
    else:
        break
print(ans)
