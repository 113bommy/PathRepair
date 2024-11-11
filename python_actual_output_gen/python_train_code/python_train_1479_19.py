n = int(input())
l = sorted(list(map(int, input().split())))
s = 0
for i in range(0,n,2):
    s += l[i]
print(s)