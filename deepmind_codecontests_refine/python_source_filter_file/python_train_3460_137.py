r=int(input())
for i in range(r):
    a,b,c,d=map(lambda x:int(x),input().split())
    l=[a,c,d]
    for i in l:
        print(i,end=" ")