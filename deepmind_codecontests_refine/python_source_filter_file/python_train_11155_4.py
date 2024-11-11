n = int(input())
A = list(map(int, input().split()))
ans = 0
for i in range(n-1):
    if A[i] == 1 and A[i+1] == 2:
        ans += 3
    elif A[i] == 1 and A[i+1] == 3:
        ans += 4
    elif A[i] == 2 and A[i+1] == 1:
        ans += 3
    elif A[i] == 2 and A[i+1] == 3:
        print('Infinite')
        exit()
    elif A[i] == 3 and A[i+1] == 1:
        ans += 4
    else:
        print('Infinite')
        exit()
if n >= 3:
    for i in range(n-2):
        if A[i] == 3 and A[i+1] == 2 and A[i+2] == 1:
            ans -= 1
print('Finite')
print(ans)
