l,r = map(int, input().split(' '))
flag = True
for i in range(l+1,r):
    s = set(str(i))
    if len(s) == len(str(i)):
        print(i)
        flag = False
        break

if flag:
    print(-1)
