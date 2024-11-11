s = input()

cur = s[0]
cnt = 1
ans = 1

for i in range(1, len(s)):
    x = s[i]
    if(cur != x):
        ans = ans + 1
        cnt = 1
        cur = x
    else:
        if(cnt < 5):
            cnt = cnt + 1
        else:
            ans = ans + 1
            cnt = 1
            cur = x
            
print (ans)