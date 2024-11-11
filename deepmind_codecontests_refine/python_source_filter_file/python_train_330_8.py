t=int(input())
for _ in range(t):
    n=int(input())
    a=list(map(int,input().split()))
    temp=a[n//2]

    a=a[0:n//2]
    # print(a)
    if len(a)<3:
        print(0,0,0)
        continue
    while len(a)>0 and a[-1]==temp:
        a.pop(-1)
    segments=[]
    curr=1
    flag=0
    for i in range(1,len(a)):
        flag=0
        if a[i]==a[i-1]:
            curr+=1
        else:
            segments.append(curr)
            curr=1
            flag=1


    segments.append(curr)
    # print(segments)
    if len(segments)<3:
        print(0,0,0)
    else:
        i=1
        g=segments[0]
        s=segments[i]
        while i<len(segments)-1 and s<=g:
            i+=1
            s+=segments[i]
        if i==len(segments):
            print(0,0,0)
            continue
        if sum(segments[i+1:len(segments)])<g:
            print(0,0,0)
            continue
        b=sum(segments[i+1:len(segments)])
        print(g,s,b)
