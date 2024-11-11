n=int(input())

def grey(k):
    if k==1:
        A=[[0,0], [1,0], [0,1], [1,1], [2,1], [1,2], [2,2]]
        return A
    else:
        B=grey(k-1)
        M=max(B)
        a,b=M[0], M[1]
        B.append([a+1,b+1])
        B.append([a+1,b])
        B.append([a,b+1])
        return (B)

X=grey(n)
print (2*len(X))
for i in X:
    print (i[0],i[1])
        
        

    
