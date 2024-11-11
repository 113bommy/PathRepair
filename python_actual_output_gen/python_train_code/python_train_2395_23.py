temp = [int(x) for x in input().split()]
nA = temp[0]
nB = temp[1]
temp = [int(x) for x in input().split()]
k = temp[0]
m = temp[1]
A = [int(x) for x in input().split()]
B = [int(x) for x in input().split()]
if A[k-1] < B[0]:
    print('YES')
else:
    print('NO')
