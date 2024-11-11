n = int(input())
A = input().split(' ')
A.sort(key = int)
ans = 0
print(A)
for i in range(0, len(A), 2):
    ans = ans + int(A[i+1]) - int(A[i])
print(ans)
