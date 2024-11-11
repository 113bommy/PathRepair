k=int(input())
a='8'*(k//2)+'6'*(k%2)
if len(a)>18:
    print(-1)
    exit(0)
print(a)