def solve(limit, rooms):
    odd, even = 0, 0
    split = []
    for i in range(0, len(rooms), 2):
        if rooms[i] % 2:
            odd += 1
        else:
            even += 1
        
        if rooms[i+1] % 2:
            odd += 1
        else:
            even += 1
        if odd == even and i < len(rooms) - 2:
            split.append(abs(rooms[i+1] - rooms[i+2]))
    split.sort()
    i = 0 
    while i < len(split):
        if limit - split[i] > 0:
            limit -= split[i]
            i += 1
        else:
            break
    print (i)
    
n, m = map(int, input().split())
rooms = list(map(int, input().split()))
solve(m, rooms)