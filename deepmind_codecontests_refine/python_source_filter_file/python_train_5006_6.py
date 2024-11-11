r, c = map(int, input().split())
table = [[*cc, sum(cc)] for cc in (list(map(int, input().split())) for _ in range(r))]
table.append(list(map(sum, zip(*table))))
for line in table:
    print(*line)