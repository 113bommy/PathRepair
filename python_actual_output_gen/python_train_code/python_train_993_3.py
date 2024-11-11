for u in range(int(input())):
    n=int(input())
    l=list(map(int,input().split()))
    for i in range(n):
        if(i%2!=l[0]%2):
            print("NO")
            break
    else:
        print("YES")
