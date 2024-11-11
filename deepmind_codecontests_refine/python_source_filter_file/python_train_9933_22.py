n,k = list(map(int, input().split(' ')))
h = list(map(int, input().split(' ')))
cum_sum = [h[0]]
for i in range(1,n):
    cum_sum.append(cum_sum[i-1]+h[i])
min_ht = cum_sum[k-1]
index = 0
for i in range(1,n-k):
    sum_ht = cum_sum[i+(k-1)]-cum_sum[i-1]
    if min_ht > sum_ht:
        index = i
        min_ht = sum_ht
print(index+1)