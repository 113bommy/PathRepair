# your code goes here
import sys
n = int(input())
arr = list(map(int, input().split()))
no_of_five = no_of_zeros = 0
for num in arr:
    if num:
        no_of_five += 1
    else:
        no_of_zeros += 1


if no_of_five > 9:
    limit = 0
    if (no_of_five % 9 != 0 and no_of_zeros):
        limit = no_of_five - (no_of_five % 9)
    elif no_of_five % 9 == 0 and no_of_zeros:
    	limit = no_of_five
    else:
        print("-1", end='')
        sys.exit()

    for _ in range(limit):
        print("5", end='')
    if no_of_zeros:
        for _ in range(no_of_zeros):
            print("0", end='')
else:
    if no_of_zeros:
        print("0", end='')
    else:
        print("-1", end='')
