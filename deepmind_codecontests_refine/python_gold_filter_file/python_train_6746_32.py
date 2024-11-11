import bisect
n = int(input())
a_ls = []
for i in range(n):
    a_ls.append(-int(input()))
L_ls = [a_ls[0]]
for a in a_ls[1:]:
    if L_ls[-1] <= a:
        L_ls.append(a)
    else:
        L_ls[bisect.bisect_right(L_ls, a)] = a
print(len(L_ls))