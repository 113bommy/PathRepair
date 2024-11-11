import sys
lines = [line for line in sys.stdin]
W = lines[0].strip()
print(sum([1 for line in lines[1:] for w in line.split() if w == W]))