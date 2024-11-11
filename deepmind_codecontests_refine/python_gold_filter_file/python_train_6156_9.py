input()
st = input()

for i,c in enumerate(st[1:]):
    if c != st[0]:
        break

lenFirst = i + 1

for i,c in enumerate(st[-2::-1]):
    if c != st[-1]:
        break
lenLast = i + 1
if st[0] == st[-1]:
    ans = (lenFirst + 1)*lenLast + lenFirst + 1
else:
    ans = lenLast + lenFirst + 1
print(ans % 998244353)

