import math
a = sum(int(x) for x in input().split())
b = sum(int(x) for x in input().split())
n = int(input())
if n == math.ceil(a/5) + math.ceil(b/10):
    print("YES")
else:
    print("NO")