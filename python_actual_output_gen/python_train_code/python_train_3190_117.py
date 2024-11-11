#n = int(input())
var = [x for x in input().split(' ')]

# lines = []var_sort
# for i in range(n):
#     line = input()
#     if line:
#         lines.append(line)
#     else:
#         break
# faces = 0

if min(var) == var[0]:
    print('Yes')
else:
    print('No')