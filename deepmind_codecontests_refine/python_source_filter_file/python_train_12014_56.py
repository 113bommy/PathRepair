import sys
n = int(input())
sys.stdout.write(str(n+1))
for i in range(n+2, n*2):
    sys.stdout.write(" " + str(i))
