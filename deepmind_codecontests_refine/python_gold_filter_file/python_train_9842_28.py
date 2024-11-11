import math

inp = list(map(float, input().split()))
# print(inp)
d = inp[0]
h = inp[1]
v = inp[2]
e = inp[3]

# print((4 * v) / (math.pi * d * d), e)

if (4 * v) / (math.pi * d * d) > e:
    print("YES")
    print(h / (((4 * v) / (math.pi * d * d)) - e))

else:
    print("NO")
