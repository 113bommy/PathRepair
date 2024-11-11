n = int(input())
chars = []
for i in range(n):
    a, b = map(int, input().strip().split())
    chars.append((i, a, b))

new_order = sorted(chars, key=lambda x: x[2] - x[1])
# print(new_order)
total_dis = 0
for i, e in enumerate(new_order):
    total_dis += chars[e[0]][1]*i + chars[e[0]][2]*(n - i - 1)
    # print(chars[e[0]][2] / chars[e[0]][1])
print(total_dis)

def total_order(p1, p2):
    pass
    
