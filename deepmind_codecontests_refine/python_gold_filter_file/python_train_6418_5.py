#-------------Program--------------
#----Kuzlyaev-Nikita-Codeforces----
#-------------Training-------------
#----------------------------------

n=int(input())
a=list(map(int,input().split()))
b=0;c=0
for i in range(n):
    if a[i]<0:c+=a[i]
    else:
        b+=a[i]
print(b-c)