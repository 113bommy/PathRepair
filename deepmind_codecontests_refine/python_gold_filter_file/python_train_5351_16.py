r, c = [int(i) for i in input().split()]
arr = []
k = 0
r2 = r
for i in range(r):
    a = input()
    arr.append(list(a))
for i in range(r):
    if 'S' not in arr[i]:
        k += c
        r2 -= 1
for j in range(c):
    for i in range(r):
        if 'S' == arr[i][j]:
            break
    else:
        k += r2
print(k)

# a = int(input())
# b = int(input())
# k = 0
#
# if a < b:
#     while a + 1 < b:
#         if a % 2 == 0 and b % 2 == 0 or a % 2 != 0 and b % 2 != 0:
#             a += 2
#         elif a % 2 == 0 and b % 2 != 0:
#             a += 1
#         else:
#             a += 3
#         k += 1
# else:
#     while a - 1 > b:
#         if a % 2 == 0 and b % 2 == 0 or a % 2 != 0 and b % 2 != 0:
#             a -= 2
#         elif a % 2 == 0 and b % 2 != 0:
#             a -= 1
#         else:
#             a -= 3
#         k += 1
# print(k)