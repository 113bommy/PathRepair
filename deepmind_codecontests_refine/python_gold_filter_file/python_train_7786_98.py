S = int(input())

v = 1000000000
x = int((v-S % v) % v)
y = int((S+x)/v)

print("0 0 1000000000 1", x, y)
