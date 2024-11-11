s = set()
for i in range(1000):
    s.add(i*i)
n = input()
xs = [int(x) for x in input().split()]
print(max(x for x in xs if x not in s))
