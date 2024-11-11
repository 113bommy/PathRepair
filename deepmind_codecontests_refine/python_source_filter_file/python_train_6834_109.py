k = int(input())
# 2*x+y=k
if k<19:
    if k%2==0:
        print(int('8'*int((k/2))))
    else:
        print(int('8'*(k//2)+'6'))
else:
    print(-1)