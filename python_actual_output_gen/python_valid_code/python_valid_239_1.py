nums = int(input())
param = list(map(int, input().split()))
s = sum(param)

accur = 0
result = 0

for i in range(nums - 1):
    accur += param[i]
    result += s - accur

print(result)
