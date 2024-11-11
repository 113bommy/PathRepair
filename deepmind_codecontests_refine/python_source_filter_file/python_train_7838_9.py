t=int(input())
lst=list(map(int,input().split()))
z=0
q=1
lst.sort()
lst=lst[::-1]
if(t==0):
    print(0)
else:
    for i in range(len(lst)):
        z+=lst[i]
        if(t<=z):
            print(i+1)
            q=0
            break
if(q==1):
    print(-1)