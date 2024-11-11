def main():
    t=int(input())
    while(t>0):
        n=int(input())
        li2=[]
        li=list(map(int,input().split()))
        i=0
        cnt=0
        if(n==2):
            if(li[0]==li[1]):
                li2.append(li[0])
                li2.append(li[1])
            else:
                li2.append(0)
        else:
            while(i<n and cnt<=(n//2) and len(li2)<(n//2)):
                if(li[i]==li[i+1]):
                    li2.append(li[i])
                    li2.append(li[i+1])
                    i=i+2
                elif(li[i]!=li[i+1] and cnt<=(n//2)):
                    a=li[i]
                    b=li[i+1]
                    c=li[i+1+1]
                    cnt=cnt+1
                    if(c==a):
                        li2.append(c)
                        li2.append(a)
                    elif(c==b):
                        li2.append(c)
                        li2.append(b)
                    i=i+2
        print(len(li2))
        for i in li2:
            print(i,end=" ")
        print()
        t-=1
main()
            