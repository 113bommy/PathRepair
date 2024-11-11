n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
c = [0,0,0,0,0]
for i in a:
    c[i - 1] += 1
for j in b:
    c[j - 1] -= 1
c = [abs(i) for i in c]
import sys
for i in c:
    if i % 2:
        print(-1)
        sys.exit(0)
print(sum(c) // 4)