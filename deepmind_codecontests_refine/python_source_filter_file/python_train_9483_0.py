n,m=list(map(int,input().split()))



g=list(map(int,input().split()))


b=list(map(int,input().split()))

p=0
l=0
for k in range(m):
    if b[l]>=g[k]:
        if l<m-1:
            p+=1
            l+=1
        else:
            l+=1
            p+=1
            break
    else:
        pass
        

print(p)
        
