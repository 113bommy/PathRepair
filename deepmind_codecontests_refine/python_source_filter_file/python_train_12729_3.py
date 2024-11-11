a = input()
b = input()
c = input()
d = a + b
sort_d = sorted(d)
sort_c = sorted(c)
sum = 0
print(sort_d)
print(sort_c)

# for i in range(len(sort_d)):
#     for j in range(len(sort_c)):
#         if sort_d[i] == sort_c[j]:
#             print('YES')
#         else:
#             print('NO')
#     pass

if sort_d == sort_c:
    print('YES')
else:
    print('NO')