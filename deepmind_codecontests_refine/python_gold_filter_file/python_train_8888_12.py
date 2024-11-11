n = int(input())

openable = set()
not_openable = {}

for _ in range(n):
    a, b = map(int, input().split())
    if b in not_openable:
        not_openable[b] = 0
        
    if a not in openable:
        not_openable[a] = not_openable.get(a, 0) + 1
    
    openable.add(b)
    
print(sum(not_openable.values()))