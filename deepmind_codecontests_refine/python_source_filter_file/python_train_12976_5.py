bin_nums = input();

i = len(bin_nums) - 1;

bin_nums = list(map(int, bin_nums));

count = 0;
num_1s = 0;

while(i >= 0):
    
    if(i == (len(bin_nums) - 1) and not bin_nums[i]):
        count += 1;
        i -= 1;
        while(not bin_nums[i]):
            count += 1;
            i -= 1;
    else:
        i -= 1;
        while(i >= 0 and bin_nums[i]):
            num_1s += 1;
            i -= 1;
        count += num_1s + 2;
        num_1s = 0;

print(count);