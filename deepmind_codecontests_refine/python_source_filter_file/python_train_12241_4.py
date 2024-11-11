import sys


class Bracket:
    def __init__(self, t, size):
        self.deep = size
        self.type = t


n = int(input())
s = input()
deep = 0
brackets = []
max_deep = 0
for i in s:
    if i == "[":
        brackets.append(Bracket(0, deep))
        deep += 1
        max_deep = max(max_deep, deep)
    else:
        deep -= 1
        brackets.append(Bracket(1, deep))

lenght = 0

for i in range(brackets.__len__()):
    lenght += 1
    if i > 0:
        if brackets[i].type == 1 and brackets[i - 1].type == 0:
            lenght += 3
w, h = lenght, max_deep * 2 + 2
mas = [[" " for x in range(w)] for y in range(h)]


def print_bracket(deep: int, type, j):
    global mas
    if type == 0:
        mas[deep][j] = "+"
        mas[deep][j + 1] = "-"
        mas[len(mas) - deep-1][j] = "+"
        mas[len(mas) - deep-1][j + 1] = "-"
    else:
        mas[deep][j] = "+"
        mas[deep][j - 1] = "-"
        mas[len(mas) - deep-1][j] = "+"
        mas[len(mas) - deep-1][j - 1] = "-"


delta = 0
for i in range(brackets.__len__()):
    temp = 0
    if i > 0:
        if brackets[i].type == 1 and brackets[i - 1].type == 0:
            temp = brackets[i]
            delta += 3
        else:
            temp = brackets[i]
    else:
        temp = brackets[i]
    print_bracket(temp.deep, temp.type, i + delta)


def check_bottom(i, j):
    global mas
    for z in range(i, h):
        if mas[z][j] == "+":
            return True
    return False


for i in range(1, h):
    for j in range(w):
        if mas[i][j] == " " and (mas[i - 1][j] == "+" or mas[i - 1][j] == "|"):
            if check_bottom(i, j):
                mas[i][j] = "|"

for i in range(h):
    for j in range(w):
        sys.stdout.write(mas[i][j])
    if i < h - 1:
        print()
