A,B,C,D,E,F = map(int,input().split())
A *= 100
B *= 100
check = 0
for i in range(F//A+1):
    for j in range((F-(A*i))//B+1):
        if i + j == 0:continue
        for k in range(((F-(A*i))-B*j)//C+1):
            for l in range((((F-(A*i))-B*j)-C*k)//D+1):
                water = A*i+B*j
                sugar = C*k+D*l
                if water//100*E < sugar:continue
                if check < 100*sugar/(water+sugar):
                    check = 100*sugar/(water+sugar)
                    ans = [water+sugar,sugar]
print(*ans)