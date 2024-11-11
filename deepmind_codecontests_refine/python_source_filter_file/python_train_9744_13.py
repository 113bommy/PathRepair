
def ceil(n):
    int_n_plus_1 = int(n) + 1
    if n + 0.5 >= int_n_plus_1:
        return int_n_plus_1
    return int(n)

# Input
n, k = [int(i) for i in input().split()]
a = [int(i) for i in input().split()]

# 
sum = sum(a)
for i in range(0, 1000):
    num = len(a) + i
    new_sum = sum + i * k
    divide = new_sum / num
    if ceil(divide) >= k:
        print(i)
        break