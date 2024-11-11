ans = 0
a = int(input())
while a > 9:
    newA = 0
    for i in str(a):
        newA += int(i)
    a = newA
    # print(newA)
    ans += 1
print(ans)
