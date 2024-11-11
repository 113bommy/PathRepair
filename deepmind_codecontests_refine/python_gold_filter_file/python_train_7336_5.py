s = input()
t = input()
n = len(s)
ans = ""
flag = 0
for i in range(n):
    if flag == 0:
        if ord(s[i]) > ord(t[i]):
            flag = -1
            break
        elif ord(s[i]) < ord(t[i]):
            if ord(t[i]) - ord(s[i]) > 1:
                ans += chr(ord(s[i]) + 1)
                flag = 1
            else:
                s1 = s[i + 1: n]
                t1 = t[i + 1: n]
                if s1.count('z') == n - i - 1 and t1.count('a') == n - i - 1:
                    flag = -1
                    break
                elif s1.count('z') != n - i - 1:
                    ans += s[i]
                    flag = 2
                elif t1.count('a') != n - i - 1:
                    ans += t[i]
                    flag = 1
        else:
            ans += s[i]
    elif flag == 1:
        ans += 'a'
    elif flag == 2:
        ans += 'z'

if flag == -1:
    print("No such string")
else:
    print(ans)
