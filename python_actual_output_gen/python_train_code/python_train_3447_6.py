b=int(input())
g=int(input())
n=int(input())
cnt=0
if(b>=g):
    for i in range(b):
        if(g>=n-i and n-i>=0):
            #print(g,n-i)
            cnt+=1
    print(cnt)
else:
    for i in range(g):
        if(b>=n-i and n-i>=0):
            #print(g,n-i)
            cnt+=1
    print(cnt)









