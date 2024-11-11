N = int(input())
A = set()

for i in range(N):
    A ^= {int(input())}

print(len(A))