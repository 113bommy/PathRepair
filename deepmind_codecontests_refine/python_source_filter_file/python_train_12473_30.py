n = int(input())
h = (int(i) for i in input().split())
x, y = 0, abs(h[0]-h[1])
for i in range(2, n):
    v = min(x+abs(h[i-2]-h[i]), y+abs(h[i-1]-h[i]))
    x, y = y, v
print(y)
