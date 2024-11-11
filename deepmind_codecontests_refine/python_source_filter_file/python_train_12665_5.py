class Cell:
    def __init__(self, y, x, open):
        self.open = open
        self.y = y
        self.x = x
        self.count = 0


class Field:
    def __init__(self, battlefield):
        self.cells = []
        for y, line in enumerate(battlefield):
            new_line = []
            for x, cell in enumerate(line):
                new_line.append(Cell(y, x, True if cell == "#" else False))
            self.cells.append(new_line)


n, k = [int(el) for el in input().split(" ")]
battlefield = []
for i in range(n):
    battlefield.append(input())
battlefield = Field(battlefield)
for y in range(n):
    for x in range(n-k):
        suited = True
        for i in range(x, x+k):
            if battlefield.cells[y][i].open:
                suited = False
                break
        if suited:
            for i in range(x, x+k):
                battlefield.cells[y][i].count += 1
for x in range(n):
    for y in range(n-k):
        suited = True
        for i in range(y, y+k):
            if battlefield.cells[i][x].open:
                suited = False
                break
        if suited:
            for i in range(y, y+k):
                battlefield.cells[i][x].count += 1
max_count = -1
x_max = 0
y_max = 0
for y in range(n):
    for x in range(n):
        if battlefield.cells[y][x].count > max_count:
            max_count = battlefield.cells[y][x].count
            x_max = x
            y_max = y
print("{} {}".format(y_max+1, x_max+1))