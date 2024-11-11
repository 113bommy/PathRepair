n=int(input())
if n>36:
    print(-1)
else:
    a='8'*(n//2)
    if n%2!=0:
        a+='4'
    print(a)
