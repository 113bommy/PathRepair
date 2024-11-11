k=int(input())
if k>34:
    print(-1)
else:
    s='8'*(k//2)+'4'*(k%2)
    print(int(s))