from collections import Counter

n,m = map(int,input().split())
s = ""
for i in range(m):
    s = s + input()
counter = Counter(s)
for i in range(n+1):
    if counter[str(i)] % 2 != 0:
        print("NO")
        break
if i == n -1:
    print("YES")