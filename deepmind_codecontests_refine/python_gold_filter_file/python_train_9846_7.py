num = int(input())

holding_list = [int(x) for x in input().split()]





new_list = sorted(holding_list)

largest = int(new_list[-1])


count = 0
for num in holding_list:
    count += int(largest) - int(num)


print(count)


