count = int(input())
queries = []
for i in range(count):
    line = input().split()
    l, r = int(line[0]), int(line[1])
    queries.append((l, r))

def query(l, r):
    if l == r and l % 2 == 0:
        return -l
    elif l == r:
        return l
    if l % 2 == 0:
        if r % 2 == 1:
            return -1*((r+1-l)//2)
        else:
            return -1*((r+1-l)//2) + r
    else:
        if r % 2 == 0:
            return (r+1-l)//2
        else:
            return (r+1-l)//2 - r

for l, r in queries:
    print(query(l, r))