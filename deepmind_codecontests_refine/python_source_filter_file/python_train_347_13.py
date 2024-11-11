n = int(input())
lis=list(map(int,input().split()))
sor=sorted(lis)
res=sor[::-1]
for i in range(1,n):
    if lis[i-1]==lis[i]:
        continue
    for j in range(i+1,n):
 #       print(lis[i],lis[j])
        if lis[i]!=lis[j]:
            lis[i],lis[j]=lis[j],lis[i]
#            print(lis,sor,res,i,j)
            if lis!=sor and lis!=res:
                print(i+1,j+1)    
                exit()
            lis[i],lis[j]=lis[j],lis[i]
    i+=1 
 #   print(i)               
print(-1)            