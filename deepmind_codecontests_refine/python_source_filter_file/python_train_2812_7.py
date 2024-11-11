n = input()
S = list(map(int, input().split()))
q = input()
T = list(map(int, input().split()))
C = 0

for i in T:
    if i in S:
        C += 1

print(C)