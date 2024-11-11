l1, r1, l2, r2, k = map(int, input().split())
a = [[l1, -1], [r1, 1], [l2, -1], [r2, 1]]
bal = 0
a.sort()
begin = 0
end = 0
for elem in a:
    if bal == 1 and elem[1] == -1:
        begin = elem[0]
    if bal == 2:
        end = elem[0]
    bal -= elem[1]
if begin <= k <= end:
    end -= 1
print(max(0, end - begin + 1))
    