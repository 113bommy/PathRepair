N = int(input())
p = list(map(int, input().split()))
score = [0] * 101
for x in p:
    score[x] += 1

while True:
    if sum(score[i:]) < i:
        break
    i += 1
print(i-1)