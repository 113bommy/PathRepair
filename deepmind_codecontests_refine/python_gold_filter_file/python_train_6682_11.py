lucky = [4, 7]
n = 1
length = 0
while n < 10:
    check = lucky[length:(length+2**(n))]
    for x in check:
        lucky.append(int("4"+ str(x)))
    for x in check:
        lucky.append(int("7"+str(x)))
    length += 2**n
    n += 1
l, r = map(int, input().split())
ans = 0
i = 0
for num in lucky:
    if num >= r:
        ans += num * (r-l+1)
        break
    elif num >= l:
        ans += num * (num-l+1)
        l = num+1
print(ans)

    