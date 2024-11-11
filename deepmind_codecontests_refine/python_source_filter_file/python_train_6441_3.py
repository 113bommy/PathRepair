import sys
for x in sys.stdin:
 a,b,c=list(map(int,x.split()))
 print(['YES','NO'][len(set(range(1,21-sum(a,b)))-{a,b,c})/7<.5])
