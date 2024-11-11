S = input()
n = len(S)
T = n
for i in range(1, n) :
    if S[i] != S[i-1] :
        T = min(T, max(i, n-i))
print(T)
