import sys
#sys.stdin = open("input.in", "r")
#sys.stdout = open("output.out", "w")

inp = input()
q = int(inp[0])

while q:
    inp = input().split()
    x = int(inp[0])
    y = int(inp[1])
    if x - y < 2:
        print("no")
    else:
        print("yes")
    q -= 1
