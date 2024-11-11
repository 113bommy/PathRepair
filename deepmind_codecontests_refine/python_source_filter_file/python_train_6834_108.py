k = int(input())
# 2*x+y=k
if k<37:
    if k%2==0:
        print(int('8'*int((k/2))))
    else:
        print(int('8'*(k//2)+'0'))
else:
    print(-1)