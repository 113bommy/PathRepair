n = input().split(' ')
s = input()
x = int(n[1])
y = int(n[2])
com = ""
nn = 0
for i in s:
    if len(com) ==0 or com[-1] != i:
        com+=i
        if(i == '0'):
            nn+=1
if nn != 1:
    print(min(nn*y, (nn-1)*x+y))
else:
    print(y)
