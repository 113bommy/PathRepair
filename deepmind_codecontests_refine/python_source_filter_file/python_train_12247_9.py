n,d = map(int,input().split())
s = input()
i = 1
con = 0
ind = -1
res = 0
while i < n-1:
    while con < d and i < n:
        if s[i] == '1':
            ind = i
        con+=1
        i+=1
    if ind == -1:
        print(-1)
        exit()
    i = ind+1
    con = 0
    ind = -1
    res+=1
print(res)

