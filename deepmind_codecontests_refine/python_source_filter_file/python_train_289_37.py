import re
s = input()
k1 = 'keyence'
ans = 'NO'
for i in range(len(k1)):
    a = '^'+k1[:i]+'.*?'+k1[i+1:]+'$'
    if re.match(a,s):
        ans = 'YES'
print(ans)
