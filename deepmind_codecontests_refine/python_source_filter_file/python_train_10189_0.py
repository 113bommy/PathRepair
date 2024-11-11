from itertools import combinations
while 1:
 n,s=map(int,input().split())
 if n+x==0:break
 print(sum(1 for p in combinations(range(10),n)if sum(p)==s))
