i = int(input())
for x in range(i):
    l=list(map(int,input().split()))
    if(l[0]!=l[3]):
        print(l[0],l[3],sep=' ',end='\n')
    else:
        print(l[2],l[1],sep=' ',end='\n')