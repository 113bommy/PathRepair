i = int(input())
for x in range(i):
    l=list(map(int,input().split()))
    if(l[0]!=l[3]):
        print(l[0],l[3],sep=' ',end='\n')
    else:
        print(l[1],l[2],sep=' ',end='\n')