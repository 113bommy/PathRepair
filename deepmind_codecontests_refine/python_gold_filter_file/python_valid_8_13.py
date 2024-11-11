t=1
t=int(input())
for _ in range (t):
    n=int(input())
    #n,m=map(int,input().split())
    #a=list(map(int,input().split()))
    #b=list(map(int,input().split()))
    #s=input()
    #n=len(s)
    c1=c2=n//3
    if n%3==1:
        c1+=1
    elif n%3==2:
        c2+=1
    print(c1,c2)