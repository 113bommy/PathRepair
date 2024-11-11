s=input()
n=len(s)
res = -1
leng = 0
for i in range(n-2):
    if s[i] == s[i+1]:
        res = i+1
        leng = 2
        break
    elif s[i] == s[i+2]:
        res = i+1
        leng = 3
        break
if s[-2] == s[-1]:
    res = n-2
    leng = 2

if res == -1:
    print("-1 -1")
elif leng == 2:
    print(str(res)+" "+str(res+1))
else:
    print(str(res)+" "+str(res+2))