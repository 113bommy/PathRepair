chores = [int(x) for x in input().split()]
complexity = [int(x) for x in input().split()]
complexity.sort()
print(complexity[chores[2]+1]-complexity[chores[2]])
