import bisect
length = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
c = []
for i1 in range(length):
    c.append(a[i1] - b[i1])
c.sort()
print(c)
result = 0
for i1 in range(length):
    ideal = 1 - c[i1]
    index = bisect.bisect_left(c, ideal, i1+1, length)
    result += length - index
print(result)