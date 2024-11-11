n = int(input())
s = input()
ans = 0
temp = 0
if "xxx" not in s:
    print(0)
else:
    for i in range(n):
        if s[i] == 'x':
            temp += 1
        else:
            if temp > 2:
                ans += temp - 2
                temp = 0
    print(max(temp-2, ans))