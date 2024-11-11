numbers = int(input())
s = 0
d = 0
r = [int(x) for x in input().split()]
for i in range(numbers):
    tbr = -1
    if r[0] > r[-1]:
        tbr = 0
    
    if i % 2 == 0:
        s += r[tbr]
    else:
        d += r[tbr]
    
    r = r[:-1]
print(f"{s} {d}")