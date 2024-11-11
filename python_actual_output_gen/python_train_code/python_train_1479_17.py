n = int(input())
l = sorted(list(map(int,input().split())))

c = 0
for i in range(n):
    c +=l[i]
print(c)