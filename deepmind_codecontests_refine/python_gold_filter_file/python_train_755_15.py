for _ in range(int(input())):
    x=int(input())
    a=list(map(int,input().split()))
    if max(a)==min(a): print(-1)
    else:
        ax=a.index(max(a))
        if len(a)>ax+1:
         if a[ax+1]<a[ax]:
           print(ax+1)
         else:
            if ax!=0 and a[ax] not in a[:ax]:
                while a[ax-1]==a[ax]:
                    ax-=1
            else:
              while a[ax+1]==a[ax]:
                ax+=1
            print(ax+1)
        else:
            if a[ax-1]<a[ax]:
              print(ax+1)
            elif a[ax-1]==a[ax]:
                while a[ax-1]!=a[ax]:
                    ax-=1
                print(ax+1)
