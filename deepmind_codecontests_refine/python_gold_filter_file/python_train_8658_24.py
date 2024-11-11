n, l, r = list(map(int, input().split()))


min_l = [1]
max_num = 1
for i in range(n-1):
    if i < l-1:
        min_l.append(max_num * 2)
        max_num = max_num * 2
    else:
        min_l.append(1)
        
max_l = [1]
max_num = 1

for i in range(n-1):
    if i < r-1:
        max_l.append(max_num * 2)
        max_num = max_num * 2
    else:
        max_l.append(max_num)
        
print(sum(min_l), sum(max_l))