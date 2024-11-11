n = int(input())
l_arr = []
r_arr = []

for _ in range(n):
    l, r = map(int, input().split())
    l_arr.append(l)
    r_arr.append(r)

count = 0
for i in range(n):
    if r_arr[i] not in l_arr[:i]+l_arr[i+1:]:
        count += 1
print(count)
