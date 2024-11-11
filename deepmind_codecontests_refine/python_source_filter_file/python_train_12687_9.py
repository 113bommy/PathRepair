import sys
s=[list(map(int,e.split(',')))for e in sys.stdin]
print(sum(a*n for a,n in s),int([sum(x)for x in zip(*s)][1]/len(s)+.5))
