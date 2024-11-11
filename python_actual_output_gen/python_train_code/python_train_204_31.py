from sys import stdin
 
n,k = map(int, stdin.readline().split())
p = [tuple(map(int, x.split())) for x in stdin.readlines()]
p = sorted(p, key=lambda x: (-x[0], x[1]))
p.count(p[k-1]) 