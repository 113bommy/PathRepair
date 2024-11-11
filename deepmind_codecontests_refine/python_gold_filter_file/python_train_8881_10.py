t=int(input())
for i in range(t):
    n=int(input())
    a=list(map(int,input().split()))
    b=list(map(int,input().split()))
    li=[]
    if sum(a)==sum(b):
        li1=[]
        for i in range(n):
            li.append(a[i]-b[i])
        for i in range(n):
            for j in range(i+1,n):
                if li[i]>0 and li[j]<0:
                    y=min(li[i],abs(li[j]))
                    li[i]-=y
                    li[j]+=y
                    for k in range(y):
                        li1.append([i+1,j+1])
            for j in range(i+1,n):
                if li[i]<0 and li[j]>0:
                    y=min(abs(li[i]),li[j])
                    li[i]+=y
                    li[j]-=y
                    for k in range(y):
                        li1.append([j+1,i+1])
        print(len(li1))
        for i in range(len(li1)):
            print(*li1[i])
    else:
        print(-1)