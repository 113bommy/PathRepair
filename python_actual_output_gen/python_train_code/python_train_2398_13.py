def soa(n):
    lst = [0 for _ in range(n+1)]
    p = 2
    while(p*p <=n):
        if lst[p] == 0:
            c = 2
            lst[p] = 1
            for i in range(p*p,n+1,p):
                lst[i] = c
                c+=1
        p+=1
    return lst
num = int(input())
lst = soa(num)
lst = lst[2:]
lst = [x if(not x==0) else 1 for x in lst]
new = set(lst)
count = len(new)
print(count)
for j in lst:
    print(j,end = " ")