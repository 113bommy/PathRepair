n, n1, n2 = map(int, input().split())
arr = [int(x) for x in input().split()]
arr.sort()
arr.reverse()
minimum = min(n1, n2)
maximum = max(n1, n2)
add = 0
add2 = 0
print(arr)
for i in range(minimum):
    add = add + arr[i]
ans1 = add / minimum
for j in range(minimum, minimum + maximum):
    add2 += arr[j]
ans2 = add2 / maximum
print("{:.8f}".format(ans1 + ans2))