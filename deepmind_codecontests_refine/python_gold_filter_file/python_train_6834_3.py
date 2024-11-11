import sys
k=int(input())
if(k>36):
    print(-1)
    sys.exit()
if(k%2==0):
    print('8'*(k//2))
else:
    print('4'+'8'*(k//2))