k = int(input())
if k>36:print(-1)
else:
    s = '8' * (k//2)
    if k%2==1:
        s+='0'
    print(s)