S=input()
mc=[0]*2019

tg=0
digit=1
for s in S[::-1]:
    tg+=int(s)*digit
    mc[tg%2019]+=1
    digit*=10%2019

ans=sum(m*(m-1)//2 for m in mc)
print(ans+mc[0])
