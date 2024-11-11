amount = int(input())
array = [int(s) for s in input().split()]
max_ = max(array)
sum_ = sum(array)
i = 1
while i * amount - sum_ < sum_:
    i += 1
if i < max_:
    print(max_)
else:
    print(i)
