n=int(input())
l=list(map(int,input().split()))
l.sort()
l.append(1000000000000000000)
if(l[0]>1):
    print(1)
else:
    for i in range(n):
        if(l[i+1]>l[i]+1):
            print(l[i]+1)
            break
