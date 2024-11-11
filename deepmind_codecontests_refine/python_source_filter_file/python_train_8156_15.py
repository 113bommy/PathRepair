import sys
f = sys.stdin
#f = open("input.txt", "r")
x, y, a, b = map(int, f.readline().strip().split())
a1, a2 = [], []
if a+(x-a) <= b:
    print(0)
else:
    for i in range(b, y+1):
        for k in range(a, x+1):
            if k > i:
                a1.append(k)
                a2.append(i)
    print(len(a1))
    for i in range(len(a1)):
        print(a1[i], a2[i])