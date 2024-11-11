"""
line = input()
while emptyCount < 1:
    maxwidth = max(maxwidth, len(line))
    lines.append(line)
    line = input()
    if line == '':
        emptyCount += 1
    else:
        emptyCount = 0
lines.pop()
"""
from sys import stdin

maxwidth = 0
lines = []

for line in stdin:
    maxwidth = max(len(line), maxwidth)
    lines.append(line.strip())

# print(lines)
# print(f"max width is {maxwidth}")

newlines = []
isLeft = True

for line in lines:
    spaces = maxwidth - len(line)
    if spaces % 2 != 0:
        if isLeft:
            leftspace = spaces // 2
            rightspace = -(spaces//-2)
            isLeft = False
        else:
            leftspace = -(spaces//-2)
            rightspace = spaces // 2
            isLeft = True
        newline = "*" + " "*leftspace + line + " "*rightspace + "*"
        newlines.append(newline)
    else:
        newline = "*"+ (" "*(spaces//2)) + line + (" "*(spaces//2)) + "*"
        newlines.append(newline)

print("*"*(maxwidth+2))
for line in newlines:
    print(line)
print("*"*(maxwidth+2))