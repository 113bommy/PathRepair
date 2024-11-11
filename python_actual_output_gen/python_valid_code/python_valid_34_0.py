n,d = map(int,input().split())
s = list(input())
lili = list()

for i in range(len(s)):
    if s[i] == '1':
        lili.append(i+1)
jmp = 0
lili.reverse()
curr_sum = 0
flag = 0
diff = 0
for i in range(len(lili)-1):
    if lili[i]-lili[i+1] > d:
        print(-1)
        flag = 1
        break
    else:
        diff = lili[i] - lili[i+1]
        if curr_sum + diff >= d:
            jmp += 1
            curr_sum = diff
        else:
            curr_sum += diff
        
if flag == 0:
    if curr_sum <= d:
        jmp += 1
    print(jmp)
        