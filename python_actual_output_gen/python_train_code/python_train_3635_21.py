from sys import stdin
two, three, five, six = map(int, stdin.readline().rstrip().split(' '))
 
num_256 = min(two, five, six)
print(256 * num_256 + 32 * min(two-num_256, 3))