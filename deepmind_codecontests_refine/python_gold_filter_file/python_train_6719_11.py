#----Kuzlyaev-Nikita-Codeforces-----
#------------03.04.2020-------------

alph="abcdefghijklmnopqrstuvwxyz"

#-----------------------------------

n,a=map(int,input().split())
t=list(map(int,input().split()))
E=t[a-1];a-=1
for i in range(1,max(a,n-a-1)+1):
    if a+i>n-1:E+=t[a-i]
    elif a-i<0:E+=t[a+i]
    else:
        E+=2*t[a+i]*t[a-i]
print(E)