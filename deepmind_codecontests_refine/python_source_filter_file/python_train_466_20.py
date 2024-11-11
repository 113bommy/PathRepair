m = [int(x) for x in input().split()]
w = [int(x) for x in input().split()]
sb, ub = [int(x) for x in input().split()]
time = []
answer = 0
for i in range(5):
    answer += max(0.3 * 500 * (i + 1), (1 - m[i] / 250) * 500 * (i + 1) - 50 * w[i])
answer += 100 * sb - 50 * ub
print(answer)