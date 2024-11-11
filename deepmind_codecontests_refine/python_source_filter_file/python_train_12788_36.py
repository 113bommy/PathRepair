A,B,C,D,E,F=map(int,input().split())

water=[]
for i in range(31):
    for j in range(30):
        if (A*i+B*j)*100<=F:
            water.append((A*i+B*j)*100)
sugar=[]
for i in range(501):
    for j in range(500):
        if C*i+D*j<=F//2:
            sugar.append(C*i+D*j)

ans_sum=0
ans_sugar=0
ans_rate=0
for i in water:
    for j in sugar:
        if i==0:
            continue
        if i+j<=F and ans_rate<j/i<=E/100:
            ans_sum=i+j
            ans_sugar=j
            ans_rate=j/i

print(ans_sum,ans_sugar)