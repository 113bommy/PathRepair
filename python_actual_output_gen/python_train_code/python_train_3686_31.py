for i in range(int(input())):
    garland = list(map(int,input().split()))
    f = max(garland)
    garland.remove(f)
    if f-sum(garland)>0:
        print("No")
    else:
        print("Yes")
