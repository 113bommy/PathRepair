from itertools import permutations, product

n = int(input())
nums = list(map(int, input().split()))
# print(nums)
indexed = sorted(zip(nums, range(1, len(nums)+1)))

removed = 0
while len(indexed) > 0 and indexed[0][0] <= removed:
    indexed = indexed[1:]
    removed += 1
while len(indexed) > 0 and indexed[-1][0] >= len(indexed):
    indexed = indexed[:len(indexed)-2]

if len(indexed) <= 2:
    print("! 0 0", flush=True)
    exit(0)

groups = []

# roads = {
#     (1, 5), (5, 6), (6, 1), (4, 2),
#     (2, 3), (3, 4), (1, 2), (1, 3),
#     (1, 4), (5, 4), (5, 3), (5, 2),
#     (6, 4), (6, 3), (6, 2),
# }


prev_value = -1
for value, index in indexed:
    if prev_value != value:
        groups.append([])
    groups[-1].append((value, index))
    prev_value = value

# print(indexed)
# print(groups)

max_groups = []

for i in range(len(groups)):
    for j in range(i, len(groups)):
        if i != j or len(groups[i]) >= 3:
            max_groups.append((abs(groups[i][0][0] - groups[j][0][0]), (i, j)))

max_groups.sort(reverse=True)
# print(max_groups)

for _, (start, end) in max_groups:
    for v1, i1 in groups[start]:
        for v2, i2 in groups[end]:
            if i1 != i2:
                print(f"? {i2} {i1}", flush=True)
                ans = input()
                # if (i2, i1) in roads: 
                if ans.lower().strip() == 'yes':
                    print(f"! {i1} {i2}", flush=True)
                    exit(0)
exit(1)
print("! 0 0")
# print(f"! {groups[0][0][1]} {groups[-1][-1][1]}", flush=True)
# filtered = [i for i in nums if i != n-1 and i != 0]
# 
# # print(filtered)
# print("? 1 2", flush=True)
# ans = input()
# else:
#     low = nums.index(min(filtered))+1
#     # print(f"{low=}")
#     # print(nums[0:low-1])
#     # print(nums[low:])
#     try:
#         high = nums.index(max(filtered), 0, low-1)+1
#     except ValueError:
#         high = nums.index(max(filtered), low)+1
#     print(f"! {low} {high}", flush=True)
