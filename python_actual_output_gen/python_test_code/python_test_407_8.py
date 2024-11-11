import sys
inp = input().split(' ')
n = int(inp[0])
m = int(inp[1])
students = [string.strip() for string in sys.stdin]
besties = set()
for i in range(m):
    maxi = -1
    index = {0}
    for j in range(n):
        if int(students[j][i]) > int(maxi):
            maxi = students[j][i]
            index.add(j)
        elif int(students[j][i]) == int(maxi):
            index.add(j)
    besties |= index

print(len(besties))
