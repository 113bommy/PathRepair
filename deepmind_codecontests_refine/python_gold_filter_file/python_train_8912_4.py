n = int(input())
s = input()
d = {0:-1}
mx = 0
sm = 0
for i in range(n):
    sm +=1 - (s[i] == '0')*2
    if sm not in d:
        d[sm]=i
    else:
        if i - d[sm]>mx:
            mx=i-d[sm]
print(mx)