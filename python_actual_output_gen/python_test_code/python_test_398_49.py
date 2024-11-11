import sys
 
read = lambda: sys.stdin.readline().rstrip()
 
n = int(read())
N = tuple(map(int,read().split()))
 
ans = 1
for i in range(n):
    ans *= N[i]
 
print("HARD" if ans == 1 else "EASY")