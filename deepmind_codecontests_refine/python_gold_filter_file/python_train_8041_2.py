for i in range(int(input())):
    n = int(input()); ae = 0; ao = 0
    a = list(map(int,input().split())); count = 0
    for j in range(n):
        if a[j]%2==0: ae+=1
        else: ao+=1
    if n%2!=0:
        if ae==ao+1:
            for k in range(len(a)):
                if a[k]%2 != k%2 and a[k]%2!=0:
                    count+=1
                else: continue
            print(count)
        else: print(-1)
    elif n%2==0:
        if ae == ao:
            for k in range(len(a)):
                if a[k]%2 != k%2 and a[k]%2==0:
                    count+=1
                else: continue
            print(count)
        else:print(-1)
    # print(count)



