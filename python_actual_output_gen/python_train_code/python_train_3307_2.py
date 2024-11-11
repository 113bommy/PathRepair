[n, k], tabs, max_tabs = [int(x) for x in input().split()], [int(x) for x in input().split()], 0
tab_sum = sum(tabs)
for i in range(n//k):
    curr_sum = 0
    for j in range(i, n, k):
        curr_sum += tabs[j]
    max_tabs = max(max_tabs, abs(tab_sum-curr_sum))
print(max_tabs)
