n,h = map(int, input().split())
l = [1 if i<h else 2 for i in list(map(int, input().split()))]
print(sum(l))
