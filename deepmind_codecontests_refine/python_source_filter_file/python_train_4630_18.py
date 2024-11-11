n = int(input())
b = [int(i) for i in input().split(' ')]
skill = {1:[], 2:[], 3:[]}
for idx, i in enumerate(b):
    skill[i].append(idx)
min_result = min(len(skill[1]),len(skill[2]),len(skill[3]))
print(min_result)
for i in range(min_result):
    print(skill[1][i], skill[2][i], skill[3][i])