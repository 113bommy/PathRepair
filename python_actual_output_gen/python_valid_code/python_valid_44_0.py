#----Kuzlyaev-Nikita-Codeforces-----
#------------02.04.2020-------------

alph="abcdefghijklmnopqrstuvwxyz"

#-----------------------------------

q=int(input())
for i in range(q):
    l,r=map(int,input().split())
    if (r+l)%2==1:
        if l%2==0:
            print(-((r-l+1)//2))
        else:
            print((r-l)//2)
    else:
        if l%2==1:
            print(-((r+l)//2))
        else:
            print((r+l)//2)    
    