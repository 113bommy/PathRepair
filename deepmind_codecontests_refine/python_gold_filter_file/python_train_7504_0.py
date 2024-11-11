from sys import stdout

n = int(input())
x, y = 1, 1

steps = []

for i in range(1, n):
    stdout.write("? {0} {1} {2} {3}\n".format(x + 1, y, n, n))
    stdout.flush()
    resp = input()
    if resp == "YES":
        steps.append('D')
        x += 1
    else:
        steps.append('R')
        y += 1

x, y = n, n
for i in range(1, n):
    stdout.write("? {0} {1} {2} {3}\n".format(1, 1, x, y - 1))
    stdout.flush()
    resp = input()
    if resp == "YES":
        steps.append('R')
        y -= 1
    else:
        steps.append('D')
        x -= 1

print("! {0}{1}".format("".join(x for x in steps[:n - 1]), "".join(x for x in steps[n - 1:][::-1])))
