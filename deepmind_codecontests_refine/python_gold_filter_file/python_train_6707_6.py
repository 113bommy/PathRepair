s = input()
l = [s.count('n'),s.count('e'),s.count('i'),s.count('t')]
counts = 0
while l[0]/3 >= 1 and l[1]/3 >=1 and l[2] != 0 and l[3] != 0:
    counts = counts + 1
    l[0] = l[0] - 2
    l[1] = l[1] - 3
    l[2] = l[2] - 1
    l[3] = l[3] - 1

print(counts)