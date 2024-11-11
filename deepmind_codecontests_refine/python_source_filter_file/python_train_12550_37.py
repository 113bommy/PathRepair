n, c = input().split()
n = int(n)
c = int(c)

A = input().split()

words = 0

for i in range(1, len(A)):
    if int(A[i]) - int(A[i-1]) > c:
        words = 0
    words = words + 1

print(words)