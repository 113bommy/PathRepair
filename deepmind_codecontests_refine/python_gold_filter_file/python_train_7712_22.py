n = int(input())

data = list(map(int,input().split()))


ind_l = 0
ind_r = n - 1

sum_l = 0
sum_r = 0

answer = 0
while ind_l <= ind_r:
    sum_l+=data[ind_l]
    ind_l+=1

    while (sum_l > sum_r) and ind_l <= ind_r:
        sum_r += data[ind_r]
        ind_r -= 1

    
    if (sum_l == sum_r):
        answer = sum_l

print(answer)
