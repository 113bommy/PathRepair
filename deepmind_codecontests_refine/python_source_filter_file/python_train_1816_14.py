mirror = ['A', 'H', 'I', 'M', 'O', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']
S = input()
f = 1
for i in range(len(S)):
    if S[i] != S[len(S) - 1 - i] or S[i] not in mirror:
        f = 0
        break

if f:
    print("YES")
else:
    print("NO")