N = int(input())
p = list(map(int, input().split()))
score = [0] * 101
for x in p:
    score[x] += 1
print(max(i * (sum(score[i:]) >= i) for i in range(101)))