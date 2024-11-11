N = int(input())
v = round(N ** 0.5)
while N % v != 0:
    v += 1
print(len(str(v)))