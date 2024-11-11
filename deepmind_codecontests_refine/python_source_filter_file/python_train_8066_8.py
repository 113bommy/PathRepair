import operator

n = int(input())
left_dict = {}
right_dict = {}
left, right, sum = 0, 0, 0
for i in range(n):
    x, a = map(int, input().split())
    if x > 0 : right_dict[x] = a
    else : left_dict[x] = a
    sum = sum + a

sorted_left = sorted(left_dict.items(), key = operator.itemgetter(0), reverse=True)
sorted_right = sorted(right_dict.items(), key = operator.itemgetter(0))
print(sorted_left, sorted_right)
ans = 0
i = -1
if len(sorted_left) == len(sorted_right):
    print(sum)
elif len(sorted_left) > len(sorted_right):
    for i in range(len(sorted_right)):
        ans = ans + sorted_left[i][1] + sorted_right[i][1]
    print(ans + sorted_left[i + 1][1])
else:
    for i in range(len(sorted_left)):
        ans = ans + sorted_left[i][1] + sorted_right[i][1]
    print(ans + sorted_right[i + 1][1])
    #print(ans + sorted_right[i][1])