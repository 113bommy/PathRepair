lineNum = 0
line = input()
while '1' not in line:
    lineNum += 1
    line = input()
print(abs(2-lineNum) + abs((line.index('1'))//2 - 2))