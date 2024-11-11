n = int(input())
if n==3:
    print(2,5,63)
elif n==4:
    print(2,5,20,63)
elif n==5:
    print(2,5,63,1260)
else:
    ans = []
    if n<1000:
        ans = [2,3,4,8,9,10]
        for i in range(n-6):
            ans.append(6*(i+1))
    else:
        m=-(-n//8)
        a = []
        for i in range(1, 12*m+1):
            if i % 2 == 0 or i % 3 == 0:
                a.append(i)
        b = 8*m-n
        for x in a:
            if x%6==0 and b>0:
                b-=1
            else:
                ans.append(x)
    print(' '.join(map(str, ans)))