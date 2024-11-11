import sys
n = int(sys.stdin.readline())
a = map(int, sys.stdin.readline().split())
daa={}
for x in a:
    daa[x]=daa.get(x,0)+1
print((int)(sum([x/2 for x in daa.values()])//2))