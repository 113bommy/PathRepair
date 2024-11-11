n, x = [int(x) for x in input().split()]
an = list(map(int,input().split()))

answer = 0
for i in range(1, n):
    tmp = max(0, an[i] + an[i-1] - x)
    answer += tmp
    an[i] -= tmp
print(answer)
