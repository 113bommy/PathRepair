#-------------Program--------------
#----Kuzlyaev-Nikita-Codeforces----
#-------------Training-------------
#----------------------------------

t=int(input())
for i in range(t):
    n,m=map(int,input().split())
    a=list(map(int,input().split()))
    E=0
    for j in range(1,n):
        E+=a[j]
    print(min(m,a[0]+E))