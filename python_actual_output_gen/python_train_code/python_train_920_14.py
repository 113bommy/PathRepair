from sys import stdin
n = stdin.readline()
l = list(stdin.readline().split())
n4 = l.count('4')
n3 = l.count('3')
n2 = l.count('2')
n1 = l.count('1')

tot = n4
#coppie 3 - 1
x = min(n3,n4)
tot += x
n3 -= x
n1 -= x
tot += n3

# coppie 2 - 2
x = n2//2
n2 = n2%2
tot += x

#  2 - 1 / 2 - 1
if n2 == 1 and n1 > 0:
    n2 = 0
    tot += 1
    if n1 == 1:
        n1 = 0
    else:
        n2 -=2
tot += n2

# 1
tot += round(n1/4 + 0.4)
print(tot)
