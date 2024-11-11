def solution(a):
    ans = 0
    for mx in range(31):
        cum_sum = 0
        cum_sum_min = 0
        for val in a:
            cum_sum += -1e+7 if val > mx else val 
            cum_sum_min = min(cum_sum_min, cum_sum) 
            ans = max(ans, (cum_sum-cum_sum_min)-mx)  # s[j] を求めているのとほぼ同義
    return ans

n = int(input())
a = list(map(int, input().split()))

print(int(solution(a)))