T=int(input())
for i  in range(T):
    t=int(input())
    s=input( )
    if(t==1):
        print(s)
        print(1)
        continue
    mins=s[:]
    winner=1
    for k in range(2,t):
        if((t-k)%2==0):
            new=s[k-1:]+s[k-2::-1]
        else:
            new=s[k-1:]+s[:k-1]
        if  new <mins:
            mins=new
            winner=k
    if s[::-1]<mins:
        print(s[::-1])
        print(t)
    else:
        print(mins)
        print(winner)