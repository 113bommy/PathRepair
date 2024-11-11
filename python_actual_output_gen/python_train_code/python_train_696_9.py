num_cases = int(input())
nums = [int(x) for x in input().split()]
uniques = set(nums)
if len(uniques) == 1:
    d = 1
elif len(uniques) == 2:
    d = max(uniques) - min(uniques)
    if d % 2 == 0:
        d = d / 2
elif len(uniques) > 3:
    d = -1
else:
    for n in uniques:
        if n != max(uniques) and n != min(uniques):
            if (max(uniques) + min(uniques)) / 2 != n:
                d = -1
            else:
                d = max(uniques) - n

print(int(d))
