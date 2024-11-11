import sys
rl = lambda: sys.stdin.readline()

n, k, m = tuple(map(int, rl().split()))
words = rl().rstrip().split()
costs = [int(cost) for cost in rl().rstrip().split()]

for _ in range(k):
    group = [int(num) for num in rl().rstrip().split()]
    if group[0] == 0:
        continue
    else:
        min = 1000000001
        for i in range(group[0]):
            if costs[group[i+1]-1] < min:
                min = costs[group[i+1]-1]
        for i in range(group[0]):
            costs[group[i+1]-1] = min

word_dict = {}
for i in range(n):
    word_dict[words[i]] = costs[i]

final_str = rl().rstrip().split()
sum = 0
for word in final_str:
    sum += word_dict[word]
print(sum)
