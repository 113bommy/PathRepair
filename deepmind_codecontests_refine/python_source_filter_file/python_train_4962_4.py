n, a, b, c, t = [int(x) for x  in input().split()]
s = 0
for i in [int(x) for x in input().split()]:
    s ++ max(a, a-b*(t-i)+c*(t-i))
print(s)    