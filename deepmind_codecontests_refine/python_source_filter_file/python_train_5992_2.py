n = int(input())
A = list(map(int, input().split(' ')))
B = []

for i in range(n):
    k = [A[i], i+1]
    B.append(k)

B.sort()
print(B)

for i in range(n//2):
    print(B[i][1], B[n-i-1][1])