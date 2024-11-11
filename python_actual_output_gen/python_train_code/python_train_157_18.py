import sys
t = int(sys.stdin.readline())
for i in range(t):
    a,b = map(int,sys.stdin.readline().split())
    sys.stdout.write(str(min(a,b,(a+b)//3)))