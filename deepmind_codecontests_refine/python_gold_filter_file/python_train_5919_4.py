N = int(input())
A = [int(i) for i in input().split()]
ret = 1
up, down = False, False
for i in range(N - 1):
    if A[i] < A[i + 1]:
        up = True
    elif A[i] > A[i + 1]:
        down = True
    if up == down == True:
        ret += 1
        up, down = False, False
print(ret)
