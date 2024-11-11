n = int(input())
A = list(map(int, input().split()))

max_length = 1
accumulate = 1

for i in range(1, len(A)):
    if A[i] >= A[i - 1]:
        accumulate += 1
    else:
        accumulate = 1
    if accumulate > max_length:
            max_length = accumulate
print(max_length)
