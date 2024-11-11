MOD = 10**9 + 7
n = int(input())
s = input().rstrip()

if s[0] == "W" or s[-1] == "W":
    print(0)
    exit()
front = 0
ans = 1
for i, item in enumerate(s):
    if item == "B":
        if front % 2 == 0:
            front += 1
        else:
            ans *= front
            ans %= MOD
            front -= 1
    else:
        if front % 2 == 1:
            front += 1
        else:
            ans *= front
            ans %= MOD
            front -= 1
    if front < 0:
        print(0)
        exit()
if front != 0:
    print(0)
    exit()
for i in range(1, n+1):
    ans *= i
    ans %= MOD

print(ans)