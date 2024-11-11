a,b=map(int,input().split());c,d,e=0,0,['0']
for i in range(60):
    for j in range(1,i):e.append('1'*j+'0'+'1'*(i-j-1))
for i in range(0,len(e)-1):
    if a-1>=int(e[i],2) and a-1<int(e[i+1],2):c=i
for i in range(0,len(e)-1):
    if b>=int(e[i],2) and b<int(e[i+1],2):d=i
print(d-c)