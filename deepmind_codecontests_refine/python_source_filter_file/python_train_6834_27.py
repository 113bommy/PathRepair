k = int(input())
if(k>34):
    print(-1)
else:
    if(k%2==0):
        print('8'*(k//2))
    else:
        print('8'*(k//2)+'4')