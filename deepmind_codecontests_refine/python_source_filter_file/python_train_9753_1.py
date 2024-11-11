_ =  int(input())
company={}
for i in range(_):
    x,y = map(int,input().split())
    company[str(x)]=y
for i in range(int(input())):
    x,y=map(int,input().split())
    print(company.keys())
    if str(x) in company.keys():
        if company[str(x)]<y:
            company[str(x)]=y
    else:
        company[str(x)]=y

ans =0
for k,v in company.items():
    ans+=v

print(company)
print(ans)