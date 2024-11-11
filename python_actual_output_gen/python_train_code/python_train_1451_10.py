for i in range(int(input())):
  height = int(input().split(" ")[0])
  grid = []
  for i in range(height):
    grid.append(input())
  changes = sum([i == "D" for i in grid[0]])
  changes += sum([i[-1] == "R" for i in grid])
  print(changes)