def check(s1, s2):
    global gg_wp
    gg = 0 
    while s1 != s2 and gg < len(s1):
        s3 = ""
        for i in range(1, len(s2)): 
            s3 += s2[i]
        s3 += s2[0]
        gg += 1
        s2 = s3
    if s1 == s2: 
        gg_wp += gg
    else: 
        gg_wp += 1000000000
n = int(input())
num = [] 
for i in range(n):
    s = input() 
    num.append(s)
if n == 1: 
    print(0)
    exit()
ans = 10000000000000000
s = num[0]
for i in range(len(num[0])):
    gg_wp = i
    for j in range(1, len(num)):
        check(s, num[j])
    ans = min(ans, gg_wp)
    s3 = "" 
    for i in range(1, len(s)): 
        s3 += s[i]
    s3 += s[0]
    s = s3
if ans == 10000000000000000:
    print(-1)
else:
    print(ans)