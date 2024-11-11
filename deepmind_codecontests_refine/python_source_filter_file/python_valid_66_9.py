ans = []
for i in range(1, 4000):
    if i % 3 != 0 and i % 10 != 3:
        ans.append(i)

for _ in range(int(input())):
    print(ans[int(input())])
