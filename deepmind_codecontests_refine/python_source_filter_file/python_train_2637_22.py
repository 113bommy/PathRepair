from math import ceil
n = int(input())
g = input().split()
nFour  = g.count('4')
nThree = g.count('3')
nTwo   = g.count('2')
nOne   = g.count('1')

count = nFour + nThree
if nThree >= nOne:
    nOne = 0
else:
    nOne = nOne - nThree
count += ceil((nOne + nTwo)/4)
print(count)
    

