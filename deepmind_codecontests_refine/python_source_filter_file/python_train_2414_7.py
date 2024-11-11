import math

n = int(input())
s = input()

if n>len(s):
    print('1'+'0'*(n-1))
elif len(s)%n!=0:
    cnt = math.ceil(len(s)/n)
    res = '1' + '0'*(n-1)
    print(res*cnt)
else:
    val = len(s)//n
    if len(set(s))==1 and s[0]=='9':
        print(('1'+'0'*(n))*val)
    else:
        res1 = s[0:n]*val
        if(res1>s):
            print(res1)
        else:
            res2 = str(int(s[0:n])+1)*val
            print(res2)