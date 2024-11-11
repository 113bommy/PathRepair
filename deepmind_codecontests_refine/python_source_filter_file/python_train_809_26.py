N = int(input())
a = list(map(int, input().split()))
temp = 0

for i in range(N):
    temp = temp ^ a[i]

if temp^temp == temp:
    print('YES')
else:
    print('NO')