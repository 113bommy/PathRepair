t = list(map(int, input().split()))
n = t[0]
B = t[1]
A = list(map(int, input().split()))
balance = 0
bits = []
for i, v in enumerate(A):
    if v % 2 == 0:
        balance += 1
    else:
        balance -= 1
    if balance == 0 and i != len(A) - 1:
        bits.append(abs(A[i-1] - v))
ans = 0
for coast in sorted(bits):
    if coast <= B:
        B -= coast
        ans += 1
    else:
        break
print(ans)