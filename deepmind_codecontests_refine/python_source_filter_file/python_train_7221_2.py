# 263A

a_i,a_j=0,0
b_i,b_j=2,2
m=[]
for i in range(5):
    s=list(map(int,input().split(' ')))
    m.append(s)
    
for i in range(5):
    for j in range(5):
        if m[i][j]==1:
            a_i,a_j=i,j
            break

moves=0

while(1):
    if a_i>b_i:
        m[a_i][a_j]=0
        a_i-=1
        m[a_i][a_j]=1
        moves+=1
    if a_i<b_i:
        m[a_i][a_j]=0
        a_i+=1
        m[a_i][a_j]=1
        moves+=1
        
    if a_j>b_j:
        m[a_i][a_j]=0
        a_j-=1
        m[a_i][a_j]=1
        moves+=1
    if a_j<b_j:
        m[a_i][a_j]=0
        a_j+=1
        m[a_i][a_j]=1
        moves+=1
        
    if a_i==b_i and a_j==b_j:
        break;
        
print(moves,m)