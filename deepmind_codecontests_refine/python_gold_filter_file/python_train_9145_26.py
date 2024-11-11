k, t = map(int, input().split())
a = sorted(list(map(int, input().split())))

b = a.pop()
print(max(0,b-sum(a)-1))