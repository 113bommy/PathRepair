# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

n = int(input())
ans = []
for _ in range(n):
    a = int(input())
    b = int(input())
    s = a+b
    if s >= 10**79:
        ans.append("overflow")
    else:
        ans.append(str(s))
print("\n".join(ans))

