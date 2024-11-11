for i in range(int(input())):
    n = int(input())
    l = list(map(int,input().split()))
    a = []
    for i in range(len(l)):
        p = i + l[i]%n
        a.append(p)
    #print(p)
    if(len(list(set(a)))==len(a)):
        print("YES")
    else:
        print("NO")
