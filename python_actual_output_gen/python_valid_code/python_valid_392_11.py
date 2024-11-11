n = int(input(),2)
# print(n)
count = 0
i = 1
flag = True
# print(n)
for j in range(50):
    if i >= n:
        print(count)
        break
    i = i * 4
    count += 1


    # if n > 0:
    #     if n % 4 != 0:
    #         if n != 1:
    #             flag = False
    #     n = n // 4
    #     count += 1
    #
    # else:
    #     if flag == True:
    #         count -= 1
    #     print(count)
    #     break