k=int(input())
a=""
if k>36:
    print(-1)
else:
    for i in range(k//2):
        a+='8'
    if k%2==1:
        a+='0'
    print(a)