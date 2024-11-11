nm = input()
n = int(nm[0])
m = int(nm[2])
a = list(map(int, input().split()))
b = list(map(int, input().split()))

# a_index = 0
# base = 0
# ans = []
# for i in range(m):
#     if b[i] > base + a[a_index]:
#         base += a[a_index]
#         a_index += 1
#     ans.append((a_index + 1, b[i] - base))
#
# for a in ans:
#     print(str(a[0]) + " " + str(a[1]))

ps = [1]
acc = 0
for i in range(n - 1):
    acc += a[i]
    ps.append(acc + 1)

for i in range(m):
    low = 0
    high = n
    while low < high - 1:
        mid = (low + high) // 2
        if ps[mid] > b[i]:
            high = mid
        else:
            low = mid

    print(str(low + 1) + " " + str(b[i] - ps[low] + 1))
