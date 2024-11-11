n = int(input())
last = float("inf")
l = 0
a = list(map(int, input().split()))
a.sort(reverse = True)
for i in a:
    m = min(last, i)
    l += m
    last = m-1
print(l)
