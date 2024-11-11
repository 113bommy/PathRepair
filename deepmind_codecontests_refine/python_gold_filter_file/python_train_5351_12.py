nums = input().split()
mainlst = []
pieces = 0
for i in range(int(nums[0])):
    a = list(input())
    mainlst.append(a)

mainlst2 = []
for i in mainlst:
    if "S" not in i:
        pieces += len(i)
    else:
        mainlst2.append(i)    

new_lst =list( zip(*mainlst2))

for i in new_lst:
    if "S" not in i:
        pieces += len(i)
        

print(pieces)