from math import ceil

l = [int(x) for x in input().split()]
n = l[0]
m = l[1]
k = l[2]
# print(l)

ar = [int(x) for x in input().split()]
ar.sort()
# ar = []
# for i in range(k, k+100):
#     ar.append(i)

res = 1
glob_cnt = 0
cnt = 1
i = 1
cur_page = (ar[0] - 1 - glob_cnt) // k
# print(cur_page)
# page = -1

while i < len(ar):
    page = (ar[i] - 1 - glob_cnt) // k
    # print(ar[i], page, cur_page, glob_cnt)
    if page == cur_page:
        cnt += 1
    else:
        res += 1
        glob_cnt += cnt
        cnt = 1
        cur_page = (ar[i] - 1 - glob_cnt) // k
    i += 1


print(res)



