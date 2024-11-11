N = int(input())
L = set()
for i in range(N):
    L ^= {input()}
print(len(L))
