t=int(input())
for t in range(t):
    p=int(input())
    q=input()
    j=0
    for i in range(len(q)):
        if q[i]=='(':
            j+=1
        else:
            if j!=0:
                j-=1
    print(i)