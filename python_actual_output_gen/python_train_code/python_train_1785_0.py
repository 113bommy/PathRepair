def prefix(a,s):
    try:
        ans = a.index(s)
        if ans == 0:
            return True
        return False
    except:
        return False
s = input()
n = int(input())
flag = False
for i in range(n):
    a = input()
    check = prefix(a,s)
    if i == 0:
        ans = a
        # print(a)
    if check and a < ans:
        flag = True
        # print(a)
        ans = a
if flag == True:
    print(ans)
else:
    print(s)
