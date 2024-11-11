import sys
l,r = map(int, sys.stdin.readline().split())
sys.stdout.write("YES\n")
for i in range(l,r,2):
    sys.stdout.write(f"{i} {i+1}\n")