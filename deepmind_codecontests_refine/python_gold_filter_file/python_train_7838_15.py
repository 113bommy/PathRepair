k=int(input())
ls=list(map(int,input().split()))
ls.sort(reverse=True)
summ=0
if sum(ls)<k:
    print(-1)
else:
    for i in range(13):
        if summ>=k:
            print(i)
            break
        summ+=ls[i]