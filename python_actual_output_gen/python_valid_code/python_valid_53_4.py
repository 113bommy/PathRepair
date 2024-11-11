nums = []
for i in range(4):
    nums.append(int(input()))
d = int(input())
cntr = 0
for i in range(d):
    for num in nums:
        if i%num==0:
            cntr+=1
            break
print(cntr)