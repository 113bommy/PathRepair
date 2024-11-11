n=int(input())
a=list(map(int,input().split()))
b=[[0 for i in range(n)] for j in range(n)]
o0=[]
o1=[]
o2=[]
o3=0

z=set(a)
for e in z:
    r=a.count(e)
    
    if r % 2==1:
        o1+=[e]
        r-=1
    if r % 4==2:
        o2+=[e]
        r-=2
    if r % 4==0:
        
        for i in range(r// 4):
            o0+=[e]
    
    else:
        o3=1
        
'''print(o0,o1,o2)'''  
c=o0
c1=o0[(n//2)**2:]*2+o2
if o3!=0:
    
    print ("NO")
elif n%2==0:
    if len(o1)!=0 or len(o2)!=0:
        print("NO")
    else:
        print("YES")
        for j in range(n//2):
            for i in range(n//2):        
                
                b[j][i]=c[(j*(n//2))+i]
                b[n-1-j][i]=c[(j*(n//2))+i]
                b[j][n-1-i]=c[(j*(n//2))+i]
                b[n-1-j][n-1-i]=c[(j*(n//2))+i]        
        for j in range(n):
            for i in range (n):
                print(b[j][i], end=' ')
            print()                
else:
    if len(o1)>1 or len(o0)!=n*n-2*n+1 or (len(o1)+len(o2)*2+len(o0)*4) != n*n:
        print ("NO")
    else:
        print ("YES")
        for j in range((n)//2):
            for i in range((n)//2):
                '''  print(i,j)'''
                b[j][i]=c[(j*(n//2))+i]
                b[n-1-j][i]=c[(j*(n//2))+i]
                b[j][n-1-i]=c[(j*(n//2))+i]
                b[n-1-j][n-1-i]=c[(j*(n//2))+i]
        ''' print(c1)'''
        for j in range(n//2):
            
            
            b[j][(n)//2]=c1[j]
            b[n-1-j][(n)//2]=c1[j]
        for j in range (n//2):
            b[(n)//2][j]=c1[j+n//2]
            b[(n)//2][n-1-j]=c1[j+n//2]
            
            
        b[(n)//2][(n)//2]=o1[0]
        for j in range(n):
            for i in range (n):
                print(b[j][i], end=' ')
            print()        
    