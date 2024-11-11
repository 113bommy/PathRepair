import sys
input = sys.stdin.readline

INF = 10 ** 9
MOD = 10 **9 + 7

N = int(input())

C = [int(input()) for _ in range(N)]
lst = [INF] * (2 * 10 ** 5 + 10) #各番号がどこにあるかを管理するリスト
ans = [1] * N
 
lst[C[-1]] = N - 1

for i in range(N - 2, -1, -1):
    c = C[i]
    if lst[c] == INF or lst[c] == i + 1:
        ans[i] = ans[i + 1]
    else:
        ans[i] = ans[i + 1] + ans[lst[c]]
    lst[c] = i

# print (ans)
print (ans[0] % MOD)