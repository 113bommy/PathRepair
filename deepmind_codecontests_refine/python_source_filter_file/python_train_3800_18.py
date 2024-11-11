n, x = map(int, input().split())
s = 0
# if x > n:
#     for i in range(2, n+1):
#         if x%i == 0:
#             s += 1
# else:
#     for i in range(1, n+1):
#         if x%i == 0:
#             s += 1
# print(s)
for i in range(1, n):
    if x%i == 0 and x/i <= n:
        s +=1
print(s)