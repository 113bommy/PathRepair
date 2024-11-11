x, y, z, k = map(int, input().split())
m = []
for _ in range(3):
    m.append(sorted(list(map(int, input().split())), reverse=True))
 
def sorted_sum(list_a, list_b):
    s = []
    for x in list_a:
        for y in list_b:
            s.append(x + y)
    return sorted(s, reverse=True)
 
ans = sorted_sum(sorted_sum(m[0], m[1])[0:k], m[2])
for i in range(0, k):
    print(ans[i])