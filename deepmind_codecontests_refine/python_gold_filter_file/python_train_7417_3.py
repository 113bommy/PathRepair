t=int(input())
while(t>0):
    t-=1
    n=input()
    i=1
    s=n[0]
    while(i<len(n)-1):
        s+=n[i]
        i=i+2
    s+=n[-1]
    print(s)

    
