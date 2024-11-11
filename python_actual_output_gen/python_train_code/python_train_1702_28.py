n, a, b = map(int, input().split())
chores = [int(i) for i in input().split()]

chores.sort()
print(chores[b]-chores[a])