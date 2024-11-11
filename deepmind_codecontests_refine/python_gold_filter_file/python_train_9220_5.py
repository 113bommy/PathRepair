import sys

n = int(sys.stdin.readline())

home = sys.stdin.readline().strip()

for line in sys.stdin:
    des = line.split("->")[1].strip()

if n%2 == 0:
    print("home")
else:
    print("contest")
