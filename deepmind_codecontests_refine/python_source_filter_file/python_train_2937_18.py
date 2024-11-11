(r, c) = map(int, input().split())
test = set()
ans = list()
for i in range(r):
    ans.append(list())
    for j in range(c):
        ans[-1].append(0)

b = list()
for i in range(1, r+c+1):
    b.append(i)
maxi = 0
test.add(0)
if r == 1 and c == 1:
    print(0)
elif r == 1:
    ans1 = list()
    for i in range(1, c+1):
        ans1.append(i)
    print(*ans1)
elif c == 1:
    ans1 = list()
    for i in range(1,r+1):
        ans1.append(i+1)
    for i in ans1:
        print(i)
else:
    for i in range(r):
        for j in range(c):
            x = 0
            k = 1
            while x in test:
                x = k*b[i]*b[j+r]
                k += 1
            test.add(x)
            ans[i][j] = x
            if x > maxi:
                maxi = x

    for i in ans:
        print(*i)
