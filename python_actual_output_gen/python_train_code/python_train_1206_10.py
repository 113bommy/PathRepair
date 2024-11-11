nums = input().split()
nums = [int(x) for x in nums]

other_nums = input().split()
other_nums = [int(x) for x in other_nums]

if nums[1] == 1:
    print(min(other_nums))
    
elif nums[1] == 2:
    first = other_nums[0]
    last = other_nums[-1]
    if first < last:
        print(last)
    else:
        print(first)
        
elif nums[1] == 3:
    print(min(other_nums))
    