def luckyNum(a):
    s=str(a)
    s="".join(set(s))
    b=['4','7']
    for i in s:
        if(i not in b):
            return False
    else:
        return True
n=int(input())
xit=0
if(luckyNum(n)):
    print('YES')
else:
    for j in range(4,n):
        if(luckyNum(j) and n%j==0):
            print('YES',j)
            xit=1
            break
    if(xit==0):
        print('NO')