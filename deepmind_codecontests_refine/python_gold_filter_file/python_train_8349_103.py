n=int(input())
for i in range(n):
    a,b=map(int,input().split())
    if(a<23 and b<60):
        o=23-a
        p=o*60
        q=60-b
        r=p+q
        print(r)    
    else:
        if(a==23):
            e=60-b
            print(e)
