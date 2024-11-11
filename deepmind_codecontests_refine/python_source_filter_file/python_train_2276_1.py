n, a, b = [ int(v) for v in input().split() ]
ans_list = []
for i in range(n):
    v = int(input())
    if a <= v < b:
        ans_list.append(v)
print(len(ans_list))
