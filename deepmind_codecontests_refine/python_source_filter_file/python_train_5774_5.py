import sys

def data():
    return sys.stdin.readline().strip()
    
    
        
def sp(): return map(int, data().split())    
def l(): return list(sp())

n=int(data())
res=[]
for i in range(n):
	res.append(list(data()))
even=0
flag=True
for i in range(n):
    for j in range(n):
        if i-1>=0 and res[i-1][j]=='o':even+=1
        elif i+1<n and res[i+1][j]=='o':even+=1
        elif j-1>=0 and res[i][j-1]=='o':even+=1
        elif j+1<n and res[i][j+1]=='o':even+=1
        if even%2==1:flag=False
    
if flag:print('YES')
else:print('NO')