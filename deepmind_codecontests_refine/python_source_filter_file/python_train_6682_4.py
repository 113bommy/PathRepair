lucky_nums = []
def lucky_num_gen(x):
    if len(x)<9:
        lm4 = x+'4'
        lm7 = x+'7'

        lucky_nums.append(int(lm4))
        lucky_nums.append(int(lm7))

        lucky_num_gen(lm4)
        lucky_num_gen(lm7)

#build array of all lucky numbers
lucky_num_gen('')
lucky_nums.sort()
#print(lucky_nums)

l,r = [int(i) for i in input().split()]

res = 0
lst = l
for i in range(len(lucky_nums)-1):
    if r<lst:
        break
    if lucky_nums[i]>=lst:
        res+=(lucky_nums[i]*(min(r,lucky_nums[i])-lst + 1))
        lst=lucky_nums[i]+1

print(res)