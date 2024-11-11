N = int(input())
s = [input() for i in range(N)]
M = int(input())
t = [input() for i in range(M)]
print( max( [s.count(a) - t.count(a) for a in s]) )