n = int(input())
ans = ((4 ** (n - 2)) * 6)
for i in range(2, n - 2):
    ans = ans +  (9 * ( 4 ** (n - 2)))
print(ans)
