n, p=map(int,input().split())
ans = 0
if n != 1:
    for i in range(1,int((p+1)**(1/2))+1):
        ni = i**n
        if p/ni >= 1 and p/ni == int(p/ni):
            ans = i
        elif p/ni < 1:
            break
    print(ans)
else:
    print(p)
