n = int(input())
a = list(map(int, input().split()))
m = max(a)
s = 0
for x in a:
    s += m - x;
print(s)