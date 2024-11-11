import sys
a, b, c = map(int, input().split())
for i in range(0, c + 1, a):
    if (c - i) % b == 0:
        print('Yes')
        sys.exit()
print('No')   
