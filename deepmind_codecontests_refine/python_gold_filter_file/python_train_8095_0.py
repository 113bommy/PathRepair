n = int(input())
p = [list(map(int, input().split())) for _ in range(n)]
q = [[x+y, x-y] for x, y in p]
print(max(max(q)[0] - min(q)[0], max(q, key=lambda x: x[1])[1] - min(q, key=lambda x: x[1])[1]))