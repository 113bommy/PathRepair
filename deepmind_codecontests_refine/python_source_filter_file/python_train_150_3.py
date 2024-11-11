n = int(input())
s = input()

import re
s = re.sub(r'\*+', '*', s)
#print(s)

for i in range(len(s)):
    if s[i] != '*':
        continue
    for j in range(1, len(s)):
        cur = i
        cnt = 0
        while cur < len(s):
            if s[cur] == '*':
                cnt += 1
            else:
                break
            cur += j
        if cnt >= 5:
            print('yes')
            exit(0)
print('no')
        
