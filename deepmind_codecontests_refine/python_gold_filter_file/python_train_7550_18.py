n = int(input())
s = input()
d = {}
if(len(s)>26):
    cnt = -1
elif(len(s)==1):
    cnt = 0
else:
    for i in range(0,n):
        if(s[i] in d):
            d[s[i]] += 1
        else:
            d[s[i]] = 1
    cnt = 0
    for k,v in d.items():
        if(v>1):
            cnt+=v-1
print(cnt)