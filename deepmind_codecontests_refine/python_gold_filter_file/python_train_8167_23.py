from collections import deque

def check(something, target):
    return something == target

tot, target = input().split(" ")
target = int(target)
tot = int(tot)
cells = list(map(int, input().split(" ")))

search_queue = deque()

graph = {}

i = 1
while i <= tot - 1:
    graph[i] = [i + cells[i-1], ]
    i += 1
search_queue += graph[1]

y = 0
gotit = False
while len(search_queue) != 0:
    y += 1
    elem = search_queue.popleft()
    checks = check(elem, target)
    if checks:
        print("YES")
        gotit = True
        break
    else:
        if elem > len(graph):
            break
        search_queue += graph[elem]
if not gotit:
    print("NO")
