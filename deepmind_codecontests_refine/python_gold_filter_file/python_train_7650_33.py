def is_pri(n):
    f = 0
    for i in range(2,int(n**.5)+1):
        if n%i == 0:
            f = 1
            break
    if f == 0:
        return True
    else:
        return False



def pri(n):
    r = []
    for i in range(2,n+1):
        if is_pri(i) == True:
            r.append(i)
    return r
n = int(input())

a = pri(n)
r = []

for i in a:
    j = 1
    while i**j<=n:
        r.append(i**j)
        j = j + 1

print (len(r))
for i in r:
    print (str(i)+" ",end="")
