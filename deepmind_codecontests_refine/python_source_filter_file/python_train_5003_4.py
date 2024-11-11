r, c = [int(i) for i in input().split()]
data = [[int(i) for i in input().split()] for j in range(r))]
ans = [data[i] + [sum(data[i])] for i in range(r)]
last_ans = ans + [[sum([ans[i][j] for i in range(r)]) for j in range(c+1)]]
for i in last_ans:
    print(*i)
