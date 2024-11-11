import sys
read=sys.stdin.buffer.readline

mi=lambda:map(int,read().split())
li=lambda:list(mi())
cin=lambda:int(read())

n=cin()
a=[int(el) for el in input()]
s=set(a)
print(['NO','YES'][n%2==0 and sum(a[:n//2])==sum(a[n//2:]) and ((len(s)==1 and (4 in s or 7 in s))or (len(s)==2 and 4 in s and 7 in s))])