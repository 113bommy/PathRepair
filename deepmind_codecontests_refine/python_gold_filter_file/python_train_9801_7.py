n = int(input())

arr_str = input().split()
arr = [int(x) for x in arr_str]

n_coup = int(input())

coup_str = input().split()
coup_arr = [int(x) for x in coup_str]


arr.sort(reverse=True)
#cum_sum_arr = []
cum_sum = 0

for i in range(len(arr)):
    cum_sum += arr[i]
#    cum_sum_arr.append(cum_sum)


for coupon in coup_arr:
    ans = cum_sum - arr[coupon - 1]
    print(ans)