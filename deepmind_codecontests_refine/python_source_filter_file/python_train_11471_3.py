for _ in range(int(input())):
    n=int(input())
    l=list(map(int,input().split()))
    l.sort()
    if l[0]==l[1] and l[-1]==l[-2]:
        a=l[0]*l[-1]
    else:
        print("NO")
        continue
    ans="YES"
    for i in range(2,2*n,2):
        if l[i]==l[i+1] and l[-i-1]==l[-i-2] and l[i]*l[-i-1]!=a:
            ans="NO"
            break
    print(ans)