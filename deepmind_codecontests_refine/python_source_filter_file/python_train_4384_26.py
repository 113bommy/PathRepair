w, h, k = map(int, input().split())

p = 0

for i in range(k):
    w = w-4*i
    h = h-4*i
    p += 2*(w+h-2)

print(p)