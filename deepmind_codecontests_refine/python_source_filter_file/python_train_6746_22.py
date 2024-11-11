from bisect import bisect_right

n = int(input())
a = [-int(input()) for _ in range(n)]
print(a)

lst = [a[0]]
for aa in a[1:]:
    i = bisect_right(lst, aa)
    if i == len(lst): lst.append(aa)
    else: lst[i] = aa

print(len(lst))