for i in range(int(input())):
    n=int(input())
    lst=list(map(int,input().split()))
    lst.sort()
    if (len(lst)==1):
        print(*lst)
    else:
        i=1
        maxvalue=lst[-1]
        while lst[i]!=maxvalue:
            if lst[i]==lst[i-1]:
               lst.append(lst.pop(i))
            else:
                i+=1
        print(lst)