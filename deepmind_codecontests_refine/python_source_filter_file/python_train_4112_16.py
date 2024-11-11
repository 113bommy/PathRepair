#-------------Program--------------
#----Kuzlyaev-Nikita-Codeforces----
#------------notcontest------------
#----------------------------------

n=int(input())
answer=0
for i in range(1,10):
    if n>=10**i:
        answer+=i*9*10**(i-1)
    else:
        answer+=i*(n-10**(i-1)+1)
        break
print(answer)