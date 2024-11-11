import sys

n = input()
for a,b,c in map(lambda x: map(int,x.split()),sys.stdin.readlines()):
    print("YES" if a*a+b*b==c*c else "NO")