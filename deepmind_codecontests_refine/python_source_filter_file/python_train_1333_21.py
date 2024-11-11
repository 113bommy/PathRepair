A = []
for _ in range(5):
    A.append(int(input()))
ans = sum([-10 * (-i//10) for i in A])
ans -= min([(10 - (i % 10)) % 10 for i in A])
print(ans)