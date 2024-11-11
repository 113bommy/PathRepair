num_lines = int(input())

x = 0
for i in range(num_lines):
    line = input().upper()

    if line[0] == "X":
        if line[1:] == "++": x += 1
        elif line[1:] == "--": x += 1
    elif line[-1] == "X":
        if line[:-1] == "++": x += 1
        elif line[:-1] == "--": x -= 1

print(x)
