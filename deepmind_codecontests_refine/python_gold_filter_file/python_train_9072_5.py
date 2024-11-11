n = int(input())

nn = n + 1
if nn % 2 == 0:
    ans = nn // 2
else:
    ans = (nn // 2) + 1

print(ans)
ct = 0
done = False
for i in range(1, ans+1):
    if done: break
    print(1, i)
    ct += 1
    if ct >= n: done = True

for i in range(2, ans+1):
    if done: break
    print(ans, i)
    ct += 1
    if ct >= n: done = True
