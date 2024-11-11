n = int(input())
lst = list(map(int, input().split()))
i, l, ml = 2, 1, 1
while i < len(lst):
    if lst[i - 1] * 2 >= lst[i]:
        l += 1
        if ml < l:
            ml = l
    else:
        l = 1
    i += 1
print(ml)