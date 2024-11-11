from sys import stdin, stdout
n = int(stdin.readline())
s = stdin.readline().strip()
ans = [0, 0]
label = 0
cnt = 0


for i in range(len(s)):
    if s[i] == '(':
        ans[0] = max(ans[0], cnt)
        label = 1
        cnt = 0
    elif s[i] == ')':
        if cnt:
            ans[1] += 1
        label = 0
        cnt = 0
    elif s[i] == '_':
        if label and cnt:
            ans[1] += 1
        else:
            ans[0] = max(ans[0], cnt)
        cnt = 0
    else:
        cnt += 1
        
#if cnt:
    #ans[0] = max(ans[0], cnt)
    

stdout.write(' '.join(list(map(str, ans))))