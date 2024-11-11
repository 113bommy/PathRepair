I = lambda: map(int, input().split())
k, = I()
num, = I()
numlist = list(map(int, list(str(num))))
numlist = sorted(numlist)
ln = len(numlist)
diff = k - sum(numlist)
ans = 0
for i in range(0, ln-1):
    if diff <= 0:
        break
    ans += 1
    diff -= 9-numlist[i]
print(ans)