def toggle(pos, count):
    i = int(pos[0])
    j = int(pos[1])
    
    if count % 2 != 0:
        if data[i][j] == 0:
            data[i][j] = 1
            return True
        elif data[i][j] == 1:
            data[i][j] = 0
            return True
    else:
        return False
            
data = [[1, 1, 1],
        [1, 1, 1],
        [1, 1, 1]]
number = []
n = 3
[number.append(input().split(" ")) for i in range (n)]
for i in range (n):
    for j in range (n):
        count = int(number[i][j])
        pos = [i, j]
        toggle(pos, count)
        
        if i-1 < 0:
            if j-1 < 0:
                pos = [i, j+1]
                toggle(pos, count)
                pos = [i+1, j]
                toggle(pos, count)
            elif j+1 > n-1:
                pos = [i, j-1]
                toggle(pos, count)
                pos = [i+1, j]
                toggle(pos, count)
            else:
                pos = [i+1, j]
                toggle(pos, count)
                pos = [i, j-1]
                toggle(pos, count)
                pos = [i, j+1]
                toggle(pos, count)
        elif i+1 > n-1:
            if j+1 > n-1:
                pos = [i, j-1]
                toggle(pos, count)
                pos = [i-1, j]
                toggle(pos, count)
            elif j-1 < 0:
                pos = [i-1, j]
                toggle(pos, count)
                pos = [i, j+1]
                toggle(pos, count)
            else:
                pos = [i, j-1]
                toggle(pos, count)
                pos = [i, j+1]
                toggle(pos, count)
                pos = [i-1, j+1]
                toggle(pos, count)
        else:
            if j-1 < 0:
                pos = [i, j+1]
                toggle(pos, count)
                pos = [i-1, j]
                toggle(pos, count)
                pos = [i+1, j]
                toggle(pos, count)
            elif j+1 > n-1:
                pos = [i, j-1]
                toggle(pos, count)
                pos = [i-1, j]
                toggle(pos, count)
                pos = [i+1, j]
                toggle(pos, count)
            else:
                pos = [i-1, j]
                toggle(pos, count)
                pos = [i+1, j]
                toggle(pos, count)
                pos = [i, j-1]
                toggle(pos, count)
                pos = [i, j+1]
                toggle(pos, count)
for i in range (n):
    for j in range (n):
        print(data[i][j], end = '')
    print()