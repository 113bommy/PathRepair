n = int(input())
a = list(map(int, input().split()))
ans = 1
for i in a:
    ans *= i
    if ans > 10**18:
        print("-1")
        exit()
print(ans)