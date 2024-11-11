#-------------Program--------------
#----Kuzlyaev-Nikita-Codeforces----
#------------notcontest------------
#----------------------------------

n,m=map(int,input().split())
k=(1+n)*n//2
if m>=k:m=m%k
for i in range(1,n+1):
    if m<i:
        break
    m-=i
print(m)