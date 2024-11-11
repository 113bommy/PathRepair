n = int(input()) - 1
l = list(map(int,input().split())) 
lim = l[0]
l = sorted(l[1:],reverse=True)

it = 0
res = 0
while lim <= l[it%n]:
    lim += 1
    l[it%n] -= 1
    res += 1
    if l[it%n] < l[(it+1)%n]:
        it += 1
    elif (it%n)>0 and l[it%n] < l[(it-1)%n]:
        it -= 1
print (res)
