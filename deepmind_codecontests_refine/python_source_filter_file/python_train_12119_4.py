n = int(input())
A = list(map(int, input().split()))
count = 0
p = True
for i in range(n):
    if A[i] == i:
        count += 1
    elif p and A[A[i]] == i:
        count += 2
        p = False
if count < n -1:
    count += 1
print(count)
