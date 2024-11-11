w, a, b = map(int, input().split())
d = [b+w-a, b-w-a][a<b]
print([0,d][d>0])
