N = int(input())
A = 0
B = 0
AB = 0
BtoA = 0
for i in range(N):
    s = input()
    AB += s.count('AB')
    if s[-1] == 'A':
        A += 1
    if s[0] == 'B':
        B += 1
    if s[0] == 'B' and s[-1] == 'A':
        BtoA += 1
if A == B == BtoA:
    A -= 1
answer = AB + min(N-1, min(A, B))
print(answer)