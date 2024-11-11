m = int(input())
s = 0
t = 0
for i in range(m):
    d, c = map(int, input().split())
    s += d*c
    t += c

print(t-1+(s-1)//9)