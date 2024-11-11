'''input
2 2 1 2
'''
# I am Mr.Inconsistent 
from sys import stdin


# main starts
w1, h1, w2, h2 = list(map(int, stdin.readline().split()))
 
height = h1 + h2
width = w1
area = (height + 2)* (width + 2)
area -= (h1 * w1)
area -= (h2 * w2)
area -= h2 * (w1 - w2)
print(area)