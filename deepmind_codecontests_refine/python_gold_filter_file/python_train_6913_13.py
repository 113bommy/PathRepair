n,k=map(int,input().split())
if(k==0 and n>1):
    print("No solution")
else:
    
    list1=[str(k)]
    list1=list1+["0"]*(n-1)
    s=""+"".join(list1)
    print(s)