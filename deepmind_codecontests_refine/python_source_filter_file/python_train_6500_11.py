n = int(input())
costs = list(map(int, input().split()))
t = int(input())

sum = []
sum.append(costs[0])
for i in range(1,n):
    sum.append(sum[i-1] + costs[i])

mod = sorted(costs)
sum_ = []
sum_.append(mod[0])
for i in range(1,n):
    sum_.append(sum_[i-1] + mod[i])
for _ in range(t):
    type, l, m = map(int, input().split())
    if type == 1:
        if l>1:
            print(sum[m-1]-sum[l-2])
        else:
            print(sum[m-1]-0)
    else:
        if l>1:
            print(sum[m-1]-sum[l-2])
        else:
            print(sum[m-1]-0)
