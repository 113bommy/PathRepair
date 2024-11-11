n = int(input())
t = input()
A = "abcdefghijklmnopqrstuvwxyz"
D = {}
for i in A:
    D[i] = 0
for i in t:
    D[i] += 1
for i in range(25):
    for j in range(D[A[i]]):
        print(A[i], end='')
print('')
