n,m=map(int,input().split())
s=list(input().split(" "))[:n]
t=list(input().split(" "))[:m]
q=int(input())
for i in range(q):
    year=int(input())
    ins=(year%n)
    intl=(year%m)
    if(ins!=0 and intl!=0):
        print(s[ins-1]+t[intl-1])
    elif(ins==0 and intl!=0):
        print(s[n-1]+t[intl-1])
    elif(ins!=0 and intl==0):
        print(s[ins-1]+t[m-1])
    elif(ins==0 and intl==0):
        print(s[n-1]+s[m-1])




