grid=[]
for i in range(3):
    inp = input()
    inp = inp[:3]+inp[4:7]+inp[8:]
    grid.append(inp)
inp = input()
for i in range(3):
    inp = input()
    inp = inp[:3]+inp[4:7]+inp[8:]
    grid.append(inp)
inp = input()
for i in range(3):
    inp = input()
    inp = inp[:3]+inp[4:7]+inp[8:]
    grid.append(inp)
inp = input().split(" ")
x = int(inp[0])
y = int(inp[1])
xn = x%3
yn=y%3
xn -=1
yn-=1
if xn<0:
    xn+=3
if yn<0:
    yn+=3
check = False
for i in range(3):
    for j in range(3):
        if grid[3*xn+i][3*yn+j]==".":
            check = True
            break
    if check:
        break
if check:
    for i in range(3):
        for j in range(3):
            if grid[3*xn+i][3*yn+j]==".":
                grid[3*xn+i] = list(grid[3*xn+i])
                grid[3*xn+i][3*yn+j] = "!"
                grid[3*xn+i] = "".join(grid[3*xn+i])
else:
    for i in range(9):
        for j in range(9):
            if i<3*xn+3 and i>=xn*3 and j>=yn*3 and j<3*xn+3:
                continue
            elif grid[i][j]!=".":
                continue
            else:
                grid[i] = list(grid[i])
                grid[i][j] = "!"
                grid[i] = "".join(grid[i])
for i in range(9):
    if i%3==0 and i!=0:
        print()
    print(grid[i][:3]+" "+grid[i][3:6]+" "+grid[i][6:])
