input()
num = list(map(int, input().split()))
dic = {}
ans = 0
for i in num:
    dic[i] = dic.get(i, 0)+1
for i in num:
    flag = 1
    for j in range(32):
        if dic.get(2**j-i, 0):
            if 2**j-i == i and dic[2**j-i]>1:
                continue
            flag = 0
            break
    if flag:
        ans += 1
print(ans)
