n, k, s = [int(i) for i in input().split()]
if k * (n - 1) < s:
    print("NO")
    quit()
if s < k:
    print("NO")
    quit()
print("YES")
length = s // k + 1
remain = s % k
position = 1
count = 0
while count < k:
    if count == remain:
        length = (abs(length) - 1) * (length // abs(length))
    position +=  length
    count += 1
    print(position , end = " ")
    if (position + length > n) or (position + length <= 0):
        length = -length
print()




