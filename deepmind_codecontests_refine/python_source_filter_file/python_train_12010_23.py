n=int(input())
li=list(map(int,input().split()))
se=list(set(li))
se.sort()
if len(se)==1:
    print(se[0])
else:
    print(se[1])