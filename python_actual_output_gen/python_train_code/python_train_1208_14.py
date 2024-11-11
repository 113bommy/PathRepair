n, m=map(int, input().split())
name=[]
ip=[]
for i in range(n):
    a, b=map(str, input().split())
    name.append(a)
    ip.append(b)
#print(arr)
    
for i in range(m):
    a, b=map(str, input().split())
    c=b[:-1]
    print(c)
    if(c in ip):
        print(a,b,"#"+name[ip.index(c)])
        
        
    
