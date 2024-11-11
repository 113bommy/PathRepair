#map(int,input().split())
s = input()
res = ""
s = list(s)
i = 0
if len(s) % 2 == 0:
    i = 0
    for i in range(len(s)):
        if i % 2 == 0:
            res = s[-1] + res
            s.pop()
        else:
            res = s[0] + res
            s.pop(0)
        #print(res, s)
        i += 1
else:
    i = 0
    for i in range(len(s)):
        if i % 2 == 1:
            res += s[-1]
            s.pop()
        else:
            res = s[0] + res
            s.pop(0)
        # print(res, s)
        i += 1
print(res)