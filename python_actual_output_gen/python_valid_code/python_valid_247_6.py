n, m = map(int, input().split())
print(sorted(map(lambda v: (v[1], v[0]), enumerate(map( lambda v: (v - 1) // 2, map(int, input().split())))))[-1][1] + 1)
