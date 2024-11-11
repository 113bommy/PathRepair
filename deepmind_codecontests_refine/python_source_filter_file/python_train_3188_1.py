a = [int(i) for i in input().split()]

def getLastNum(num):
    zeros = 0
    lastNum = num%10
    num = str(num)
    for i in range(len(num) - 1, 0, -1):
        if num[i] == "0":
            zeros += 1
        else:
            lastNum = num[i]
            break
    return [int(lastNum),zeros]


lastNum,zeros = getLastNum(a[0])
x = a[0]

if zeros < a[1]:
    x = a[0]*(10**(a[1] - zeros))

possible = a[0]
hasfound = 0
while possible < x:
    lastNum, zeros = getLastNum(possible)
    if lastNum % 2 == 0 or lastNum %5 == 0:
        if lastNum % 2 == 0:
            possible *= 5
        else:
            possible *= 2
        lastNum, zeros = getLastNum(possible)
        if zeros == a[1]:
            hasfound = 1
            break;

    else:
        possible = possible * 10 **(a[1] - zeros)
        break


# if int(num[-1])%2 == 0 or int(num[-1])%5 == 0:
#     possible = a[0]
#     n = 1
#     if int(num[-1]) % 5 == 0:
#         n = 2
#         while  possible % 10 ** a[1] != 0 and possible < x:
#             possible = a[0]*n*2
#             n *= 2
#         # print(n)
#         # 199999900000000
#
#     # 124999900000000
#     elif int(num[-1])%2 == 0:
#         n = 5
#         while  possible % 10 ** a[1] != 0 and possible < x:
#             possible = a[0]*n*2
#             n += 5


#     else:
#         while possible > a[0]:
#             if possible % a[0] == 0 and possible % (10 ** a[1]) == 0 or possible%10 == a[1]:
#                 x = possible
#             possible -= 10 ** a[1]
# print(x,possible)
# if x < possible and x > a[0]:
#     print(x)
# else:
#     print(possible)
# if lastNum == 2:
#     x = a[0] * (10 ** a[1]-zeros / 2)
# elif lastNum == 5:
#     x = a[0] * (10 ** a[1] / 5)
# elif a[0]%10 == 0:
#     x = a[0] * (10 ** a[1] / 10)
if possible < x:

    print(possible)
else:
    print(x)




