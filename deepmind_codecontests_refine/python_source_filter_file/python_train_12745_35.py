"""
9 6 3
<< 3 4 5 (6) 7 8 9
17 5 2
<< 3 4 (5) 6 7 >> 
6 5 2
<< 3 4 (5) 6 
6 1 2
(1) 2 3 >> 
6 2 2
1 (2) 3 4 >>
9 6 3
<< 3 4 5 (6) 7 8 9
10 6 3
<< 3 4 5 (6) 7 8 9 >>
8 5 4
1 2 3 4 (5) 6 7 8 
"""
n,p,k=map(int,input().split())
if(p<1 or p>n):
    pass
else:
    #print(p-k,p+k)
    if(p-k>1 and p+k<n):
        print("<<"," ".join("(%d)"%(i) if i==int(((p-k)+(p+k))/2) else str(i) for i in range(p-k,p+k+1)),">>")
    elif(p-k<=1 and p+k>n):
        print(" ".join("(%d)"%(i) if i==int(((p-k)+(p+k))/2) else str(i) for i in range(p-k,p+k+1)))
    elif(p-k>1):
        print("<<"," ".join("(%d)"%(i) if i==int(((p-k)+(p+k))/2) else str(i) for i in range(p-k,n+1)))
    elif(p+k<n):
        print(" ".join("(%d)"%(i) if i==int(((p-k)+(p+k))/2) else str(i) for i in range(1,p+k+1)),">>")