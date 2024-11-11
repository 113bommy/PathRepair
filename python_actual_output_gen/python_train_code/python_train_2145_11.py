S = input()
T = input()
l = len(T)

mx = -1
for i in range(len(S) - l):
    m = [a == b for a, b in zip(S[i:i + l], T)].count(True)
    mx = max(m, mx)

print(l - mx)