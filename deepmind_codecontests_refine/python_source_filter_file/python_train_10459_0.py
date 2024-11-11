a,b = map(int,input().split())
if a==b:
    print("infinity")
elif a<b:
    print(0)
else:
    cnt = 0
    p = 1
    c = a-b
    while p*p<c:
        if c%p==0 and c//p>b:
            cnt += 1
            if p>b:
                cnt += 1
        p += 1  
    if p*p==c:
        cnt += 1  
    print(cnt)