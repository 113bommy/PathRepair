import sys
def i():
    return sys.stdin.readline()[:-1]
cases = int(i())
for x in range(cases):
    l,r = map(int,i().split())
    if l*2 <= r:
        print(l,l*2)
    else:
        print(-1)