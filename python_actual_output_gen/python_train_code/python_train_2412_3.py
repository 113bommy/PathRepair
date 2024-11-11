N = int(input())
C = list(input().split())
_C = C.copy()

for i in range(N):
    for j in range(N-1, i, -1):
        if (C[j][1] < C[j-1][1]):
            C[j], C[j-1] = C[j-1], C[j]
print(*C)
print("Stable")

for j in range(N):
    m = i
    for j in range(i, N):
        if (_C[j][1] < _C[j-1][1]):
            m = j
    _C[i], _C[m] = _C[m], _C[i]
print(*_C)
if(C ==_C):
    print("Stable")
else:
    print("Not stable")