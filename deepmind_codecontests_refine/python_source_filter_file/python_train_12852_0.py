n, k = map(int, input().split())
floors = list(sorted(list(map(int, input().split())), reverse = True))
print(sum(x - 1 for x in floors[::k]))