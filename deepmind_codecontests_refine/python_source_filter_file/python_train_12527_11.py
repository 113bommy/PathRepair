# map(int, input().split(" "))

s = input()
n = len(s)
i = 0
x = []
ans = 1
for j in s:
    if j == ".":
        x.append(i)
    i += 1

if not x:
    print("NO")
elif x[0] == 0 or n - x[-1]-1 >3 or x[-1]==n-1 or x[0] > 8:
    print("NO")
else:
    a = [s[:x[0] + 1]]
    for i in range(1, len(x)):
        if x[i] - x[i - 1] > 12 or x[i] - x[i - 1] < 2:
            ans = 0
            break
        else:
            if x[i] - x[i - 1] == 3:
                a[-1] += s[x[i - 1] + 1:x[i - 1] + 2]
                a.append(s[x[i - 1] + 2:x[i] + 1])
            elif x[i] - x[i - 1]-1 == 11:
                a[-1] += s[x[i - 1] + 1:x[i - 1] + 4]
                a.append(s[x[i - 1] + 4:x[i] + 1])
            else:
                a[-1] += s[x[i - 1] + 1:x[i - 1] + 3]
                a.append(s[x[i - 1] + 3:x[i] + 1])
    a[-1] += s[x[-1] + 1:]
    if ans:
        print("YES")
        for i in a:
            print(i)
    else:
        print("NO")
