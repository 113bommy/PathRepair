N = int(input())
A = list(map(int, input().split()))
f = [[a] for a in A]
for i in range(N):
    for j in range(1<<N):
        if j & 1<<i:
            f[j] = sorted(f[j]+f[j^1<<i], reverse=True)[:2]
Ans = [sum(f[1])]
for a, b in f[2:]:
    Ans.append(max(Ans[-1], a+b))
print("\n".join(map(str, Ans)))
