S = input()
K = int(input())
cost = [ord("z") - ord(s) + 1 for s in S]
A = [chr(ord("a") + i) for i in range(26)]

ans = ""
for i in range(len(S)-1):
    if cost[i] <= K:
        K -= cost[i]
        ans += "a"
    else:
        ans += S[i]

ans += A[(A.index(S[-1]) + K) % 26]
print(ans)
