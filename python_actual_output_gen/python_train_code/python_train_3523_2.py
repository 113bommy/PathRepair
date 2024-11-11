a = input()
b = input()
c = a.count("1")
if(c&1):
    a+='1'
j = 0
err = 0
for i in range(len(b)):
    if(b[i] == '1'):
        while(True):
            if(j>=len(a)-1):
                err = 1
                break
            if(a[j] == '1'):
                j+=1
                break
            else:
                j+=1
    if(err):
        break


if(err):
    print("NO")
else:
    print("YES")