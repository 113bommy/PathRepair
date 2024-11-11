n = int(input())
lst = set(input().split()[1:])
for i in range(1, n):
    new_lst = set(input().split()[1:])
    lst.intersection_update(new_lst)
print(' '.join(list(lst)))