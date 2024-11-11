import heapq
x, y, z = [int(item) for item in input().split()]
gsb = []
for i in range(x + y + z):
    gsb.append([int(item) for item in input().split()])
gsb.sort(key=lambda x: x[0] - x[1], reverse=True)

g_sum = sum(item[0] for item in gsb[:x])
s_sum = sum(item[1] for item in gsb[x+z:x+y+z])
b_sum = sum(item[2] for item in gsb[x:x+z])

gb_pq = [a - c for a, b, c in gsb[:x]]
sb_pq = [b - c for a, b, c in gsb[x+z:x+y+z]]
heapq.heapify(gb_pq)
heapq.heapify(sb_pq)

ans_gb = [0]
gb_total_delta = 0
for a, b, c in gsb[x:x+z]:
    new_gb = a - c
    small_gb = heapq.heappushpop(gb_pq, new_gb)
    gb_total_delta += new_gb - small_gb
    ans_gb.append(gb_total_delta)
ans_sb = [0]
sb_total_delta = 0
for a, b, c in gsb[x:x+z][::-1]:
    new_sb = b - c
    small_sb = heapq.heappushpop(sb_pq, new_sb)
    sb_total_delta += new_sb - small_sb
    ans_sb.append(sb_total_delta)
ans_sb.reverse()

max_delta = 0
for gb, sb in zip(ans_gb, ans_sb):
    max_delta = max(max_delta, gb + sb)
print(g_sum + s_sum + b_sum + max_delta)