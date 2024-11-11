n = int(input())
l = []
yearm = [0] * 366
yearf = [0] * 366
for i in range(n):
    l.append(input().split())
for i in range(366):
    for j in range(n):
        if l[j][0] == 'M':
            if int(l[j][1]) <= i <= int(l[j][2]):
                yearm[i] += 1
        else:
            if int(l[j][1]) <= i <= int(l[j][2]):
                yearf[i] += 1
maxp = 0
for i in range(366):
    if min(yearm[i], yearf[i]) > maxp:
        maxp = min(yearm[i], yearf[i])
print(maxp * 2)
    
