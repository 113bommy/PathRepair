a=int(input())
s=list(map(int,input().split()))
ina=0
iko=a-1
otvet=0
flag=1
kolna=s[ina]
kolko=s[iko]
if a==1:
    print(0)
else:

    while flag!=0:
        if kolna==kolko:
            otvet=kolna
            ina+=1
            kolna+=s[ina]
        elif kolna>kolko:
            iko-=1
            kolko+=s[iko]
        else:
            ina+=1
            kolna+=s[ina]

        if ina>=iko:
            flag=0

        #print(kolna,ina)
        #print(kolko,iko)
        #print()
    print(otvet)