A,B=input().split() 
ans=[] 
leng=len(A)
i=1
while i<leng: 
    if A[i]>B[0]:
        break
    i+=1
print(A[:i]+B[0])
        
        

