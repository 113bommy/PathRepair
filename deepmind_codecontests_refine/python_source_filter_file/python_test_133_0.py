

for _ in range(int(input())):
    n=int(input())
    l=list(map(str,input().split()))
    print(l)
    s=""+l[0]
    print(s)
    length=1
    for i in range(1,len(l)):
        if(s[length]==l[i][0]):
            s+=l[i][1]
            print(s)
            length+=1
        else:
            s+=l[i]
            length+=2
    nm=n-len(s)
    if(n==0):
        print(s)
    else:
        print(s+"a"*nm)