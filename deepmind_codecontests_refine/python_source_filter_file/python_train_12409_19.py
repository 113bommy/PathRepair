the_nums = input().split()
l = (int(the_nums[0]))
r = (int(the_nums[1]))

for index in range(l,r+1):
    for i in range(10):
        temp = str(i)
        string = str(index)
        num = string.count(temp)
        if num >= 2:
            break
        if i == 9:
            print(index)
            exit()


