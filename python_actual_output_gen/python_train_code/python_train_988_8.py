n, k = list(map(int, input().split()))
A = list(map(int, input().split()))
answer = 0
x = 1
for i in range(1, len(A)):
    if A[i] != A[i - 1]:
        x += 1
    else:
        if x > answer:
            answer = x
            x = 1
if x > answer:
    answer = x
print(answer)
