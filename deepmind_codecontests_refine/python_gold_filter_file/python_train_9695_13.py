n = int(input())
l = list(map(int, input().split()))
sub = 0
l.sort()
li = []
for i in range(0, n, 2):
    sub = l[i + 1] - l[i]
    li.append(sub)
print(sum(li))