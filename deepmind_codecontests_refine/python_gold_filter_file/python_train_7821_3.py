n = int(input())

s_i = list(map(int, input().split()))
max_possible = float('inf')
answer = 0

for i in range(len(s_i) - 1, -1, -1):
    answer += min(max_possible, s_i[i])
    max_possible = min(max_possible, s_i[i]) - 1

    if max_possible < 0:
        break

print(answer)