from operator import itemgetter
n = int(input())
num = 10**9 + 1
abi = [list(map(int,input().split())) for i in range(n)]
abi2 = [abi[i] + [abi[i][0] * num + abi[i][1]] for i in range(n)]
abi2.sort(key = itemgetter(2))
ans = 0
for i in range(n):
    if ans > abi2[i][1]:
        ans = abi2[i][0]
    else:
        ans = abi2[i][1]
print(ans)
