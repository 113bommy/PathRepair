S = input()
T = input()
d = len(S) - len(T)
print(len(T) - max(sum(t == s for t, s in zip(T, S[i : i + d + 1])) for i in range(d + 1)))