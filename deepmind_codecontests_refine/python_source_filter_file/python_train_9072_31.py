# n = int(input())
# count = 0


# def increase(A):
#     for i in range(len(A) - 1):
#         if A[i] < A[i+1]:
#             print(A[i])
#             print(A[i+1])
#             return False
#         return True


# def main(h, p):
#     maximum = max(h)
#     indexMax = h.index(maximum)
#     h[indexMax] = p[0]
#     p.pop(0)
#     p.insert(maximum)
#     return h, p


# for i in range(1):
#     h = [int(i)for i in input().split(" ")]
#     p = [int(i)for i in input().split(" ")]

# print(p)
# print(h)
# print(increase(p))
# if increase(p) == True:
#     print(0)

# # while increase(p) == False:
# #     count += 1
# #     newh, newp = main(h, p)
# #     p = newp
# #     h = newh
# # print(count)
n = int(input())
print(n//2 + 1)
for i in range(1, n):
    if i % 2 == 0:
        m = int(i//2)
        print(f'{m} {m+1}')
    else:
        m = int(i//2)
        print(f'{m+1} {m+1}')
