n, s = list(map(int, input().split()))
p = []

for i in range(n):
    p.append(list(map(int, input().split())))

p.sort(reverse=True)

time = 0
floor = s
index = 0

while(floor>0 and index < len(p)):
    if floor < index:
        index += 1
    elif floor == p[index][0]:
        if time >= p[index][1]:
            time += 1
            floor -= 1
            index += 1
        else:
            time += 1
    else:
        time += 1
        floor -= 1

print(time + floor)
    
    
