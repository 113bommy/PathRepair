ex = input()
re = input()
ans = 0
for i in ex:
    if i == '+':
        ans += 1
    else:
        ans -= 1


tot = re.count('?')
res = 0
cnt = 0

def recur(times , sumtn):
    global cnt
    # print(times , sumtn,cnt)
    if times == 0 :
        if sumtn == ans:
            cnt += 1  
        return 

    recur(times -1 ,sumtn + 1)
    recur(times -1 ,sumtn - 1)

for i in re:
    if i == '+':
        res += 1
    elif i == '-':
        res -= 1

if tot == 0 :
    if res == ans : 
        print(1)
    else:
        print(0)
else :  
    recur(tot,res)
    print(cnt/2**tot)