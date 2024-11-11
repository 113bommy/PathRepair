
n = int(input())
temp = input().split()
A = [0] * (n+1)
sum = 0

for i in range(n):
    A[int(temp[i])] = i

for i in range(n):
    sum += abs(A[i] - A[i+1])

print(sum)
