for _ in range(int(input())):
    n=int(input())
    l=[]        
    t=[0]*n
    nt=-1
    s=0
    for i in range(n):
        l = (list(map(int,input().split())))
        c=1
        check=s
        while(c<l[0]):
            if t[l[c]-1]==0:
                t[l[c]-1]=1
                s+=1
                break
            else:
                c+=1
        if s==check and nt==-1:
            nt=i
    if s==n:
        print("OPTIMAL")
    else:
        print("IMPROVE")
        for i in range(n):
            if t[i]==0:
                print(nt+1, i+1)
                break

        