s = input().replace('BC','D')
n = len(s)
 
count = 0
res = 0
 
for i in range(n):
    if s[i] == 'A':
        count += 1
    elif s[i] == 'D':
        res += count
    else:
        count = 0
print ans