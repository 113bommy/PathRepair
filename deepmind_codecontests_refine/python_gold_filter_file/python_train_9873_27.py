N, A, B = map(int, input().split())

print(sum(x for x in range(1, N+1) if A <= sum(map(int, str(x))) <= B))