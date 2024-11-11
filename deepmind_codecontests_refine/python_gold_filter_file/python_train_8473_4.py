n = int(input())
S = []
a = list(map(int, input().split()))
Ans = [0] * 10
for i in a:
    Ans[i] += 1
for i in range(1, 8):
    for j in range(i + 1, 8):
        for k in range(j + 1, 8):
            while j % i == 0 and k % j == 0 and Ans[i] > 0 and Ans[j] > 0 and Ans[k] > 0:
                S.append((i,j,k))
                Ans[i] -= 1
                Ans[j] -= 1
                Ans[k] -= 1
if len(S) == n // 3:
    for i, j, k in S:
        print(i, j, k, end= ' ')
        print()
else:
    print(-1)