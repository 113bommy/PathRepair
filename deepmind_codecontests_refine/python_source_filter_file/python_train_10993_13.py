n = int(input())
A = ["Sheldon","Leanord","Penny","Rajesh","Howard"]
k = -1
sum_tot = 0
if n <= 5:
    print(A[n-1])
else:
    while(sum_tot < n):
        k = k + 1
        sum_tot = sum_tot + ( 5 * (2 ** k) )
    useful_sum = (5 * (2 ** k)) - (sum_tot - n)
    index = 0
    while(useful_sum >= (2 ** k)):
        index = (index + 1) % 5
        useful_sum = useful_sum - (2 ** k)
    print(A[index])