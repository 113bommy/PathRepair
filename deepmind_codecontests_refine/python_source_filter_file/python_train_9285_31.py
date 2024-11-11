from collections import deque
numSticks = int(input())
lengths = [int(l) for l in input().split()]
lengths.sort() # n log n
queue = deque(lengths) # n
x = 0
y = 0
while queue: # n
    x += queue.popleft()
    if queue:
        y += queue.pop()
print(x**2 + y**2)