# link: https://codeforces.com/problemset/problem/991/C

def check(mid_k, n):
    vasya_sum = 0
    total_candies = n
    while total_candies >= 1:
        choice = min(total_candies, mid_k)
        vasya_sum += choice
        total_candies -= choice
        total_candies -= (total_candies) // 10
    if vasya_sum >= (n//2): return 1
    else:                   return 0    

for _ in range(1):
    n = int(input())
    k = 1
    start = 1
    end = n
    while start <= end:
        mid_k = start + (end - start) // 2
        if check(mid_k, n):
            k = mid_k
            end = mid_k - 1
        else:
            start = mid_k + 1
    print(k)        