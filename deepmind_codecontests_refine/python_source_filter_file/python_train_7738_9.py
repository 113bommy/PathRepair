d=input().split()
do_l=int(d[0])
ile_p=int(d[1])

liczby=[0]*(do_l+1)
i=2
pierwsze=set()
while i<=do_l:
    if liczby[i]==0:
        for j in range(i,do_l//i+1):
            liczby[i*j]+=1
        pierwsze.add(i)
    i+=1
pierwsze.remove(2)
poprzednia=2
wynik=0


for i in sorted(pierwsze):
    print(poprzednia,i,(poprzednia+i+1,(poprzednia+i+1) in pierwsze))
    if (poprzednia+i+1) in pierwsze:
        wynik+=1
        
    poprzednia=i

if wynik>=ile_p:
    print('YES')
else:
    print('NO')