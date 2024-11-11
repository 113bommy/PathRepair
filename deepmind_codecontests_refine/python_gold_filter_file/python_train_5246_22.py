n = int(input())
path = input()
startFound = False
reverse = False
i, s, t = 0, 0, 0
while True:
    # inicios
    if not startFound:
        if path[i] == 'R' and path[i-1] == '.':
            s = i+1
            startFound = True
        if path[i] == 'L' and path[i+1] == '.':
            s = i+1
            startFound = True
            reverse = True
    else:
        if path[i] == 'R' and path[i+1] == 'L':
            t = i+1
            break
        if path[i] == 'L' and path[i-1] == 'R':
            t = i+1
            break
        if path[i] == 'R' and path[i+1] == '.':
            t = i+2
            break
        if path[i] == 'L' and path[i-1] == '.':
            t = i
            break
        if path[i] == '.' and path[i-1] == 'R':
            t = i+1
            break
        if path[i] == '.' and path[i+1] == 'L':
            t = i+1
            break
    i += -1 if reverse else 1
print(s, t)
