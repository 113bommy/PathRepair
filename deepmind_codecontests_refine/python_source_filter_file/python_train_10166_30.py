import math as M

p, y = [int(x) for x in input().split()]

lim = min(int(M.sqrt(y)) + 1, p) + 1
primes = []

for n in range(2, lim):
    for m in range(2, int(M.sqrt(n)) + 1):
        if n % m == 0:
            break
    else:
        primes.append(n)

for k in range(y, 1, -1):
    for m in primes:
        if k % m == 0:
            break
    else:
        print(k)
        break
else:
    print(-1)
#
# arr = [True] * (y + 1)
# for i in range(2, min(M.ceil(M.sqrt(y)), p) + 2):
#     if arr[i]:
#         k = i
#         while k < y + 1:
#             arr[k] = False
#             k += i
#
# # print(arr)
# for k in range(y, 1, -1):
#     if arr[k]:
#         print(k)
#         break
# else:
#     print(-1)
