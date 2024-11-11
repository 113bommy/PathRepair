for _ in range(int(input())):
    n = int(input())
    lis = []
    for i in range(n):
        a,b = map(int,input().split())
        lis.append((a,b))
    lis.sort()
    print(lis)
    printx = []
    k=0
    printx.append(lis[0][0]*"R" + lis[0][1]*"U")
    
    for i in range(1,len(lis)):
        
        if lis[i][0]>=lis[i-1][0] and lis[i][1]>=lis[i-1][1]:
            
            printx.append((lis[i][0] - lis[i-1][0])*"R" + (lis[i][1] - lis[i-1][1])*"U")
        
        else:
            
            print("NO")
            k=1
            break
    if k==1:
        continue
    print("YES")
    for i in printx:
        print(i,end="")
    print()
     
        