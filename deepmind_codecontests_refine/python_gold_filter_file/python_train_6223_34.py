S = input()
T = input()
d = len(S) - len(T)
print(len(T) - max(sum(t == s for t, s in zip(T, S[i : i + len(T) + 1])) for i in range(d + 1)))