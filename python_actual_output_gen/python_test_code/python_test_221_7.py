#n = int(input())
#n, m = map(int, input().split())
#s = input()
c = list(map(int, input().split()))
a = []
p = 0
for i in range(len(c)):
    if c[i] == 1:
        if p:
            a.append(c[i - 1])
        p = 1
a.append(c[-1])
print(len(a))
print(*a)