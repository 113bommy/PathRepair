n, k = map(int, input().split())
def if_prime(num):
    if num > 1:
        for i in range(2, num):
            if (num % i) == 0:
                return False
        else:
            return True
    else:
        return False

arrp = []
c=0
for i in range(2,n):
    if if_prime(i) == True:
        arrp.append(i)

for i in range(len(arrp)-1):
    if (arrp[i]+arrp[i+1]+1) in arrp:
        c+=1

if c>=k:
    print('YES')
else:
    print('NO')