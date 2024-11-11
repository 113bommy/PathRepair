import sys
graph = []
for _ in range(4):
    graph.append(input())

for row in range(3):
    for col in range(3):
        count = {'#': 0, '.': 0}
        count[graph[row][col]] += 1
        count[graph[row+1][col]] += 1
        count[graph[row][col+1]] += 1
        count[graph[row+1][col+1]] += 1
        if count['#'] >= 3 or count['.'] >= 3:
            print('YES')
            sys.exit()
print('NO')