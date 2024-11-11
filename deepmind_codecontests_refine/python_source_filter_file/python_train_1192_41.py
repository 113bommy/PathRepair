qwer = "qwertyuiopasdfghjkl;zxcvbnm,./"
s = str(input())
st = str(input())
for i in range(len(st)):
    if s == "R":
        print(qwer[qwer.index(st[i-1])], end='')
    else:
        print(qwer[qwer.index(st[i+1])], end='')
