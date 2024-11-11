from sys import stdin
i = [[int(y) for y in x.rstrip().split()] for x in stdin.readlines()]
h = i[0][1]
print(sum(1+(x>7) for x in i[1]))