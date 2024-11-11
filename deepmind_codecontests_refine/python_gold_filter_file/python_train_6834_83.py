k=int(input())
if k<=36:
    print(int('8'*(k//2)+'9'*(k%2)))
else:
    print(-1)