n = int(input())
nums = map(int, input().split())
smallest = min(nums)
new_nums = []
for x in nums:
    if x!=smallest:
        new_nums.append(x)
if len(new_nums)==0:	
    print("NO")
else:
    print(min(new_nums))