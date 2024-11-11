import sys
input = lambda :sys.stdin.readline().rstrip('\r\n')
for _ in range(int(input())):
    l,r = map(int,input().split())
    if r%l==0:
        print(l,r)
    else:
        print(-1,-1)