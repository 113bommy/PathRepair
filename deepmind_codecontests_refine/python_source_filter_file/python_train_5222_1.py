import sys

inputlines = sys.stdin.readlines()

# inputlines = ["3 3 3", "1 1 1", "2 2 2", "3 3 3"]

# with open('testfile2', 'r') as ifile:
#     inputlines = ifile.readlines()

inputnumbers = [[int(numchar) for numchar in line.split()] for line in inputlines]

# [int(numchar) for line in inputlines
#                 for numchar in line.split()]

numspots = inputnumbers[0][0]
maxheight = inputnumbers[0][1]
numrestrictions = inputnumbers[0][2]

restrictions = [maxheight] * numspots

for restriction in inputnumbers[1:numrestrictions+1]:
    left, right, height = restriction
    for i in range(left - 1, right):
        restrictions[i] = min(restrictions[i], height)


print(restrictions)
print(sum([x**2 for x in restrictions]))
