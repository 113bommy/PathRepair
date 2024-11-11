a,b,c=map(int,input().split())
i,j=0,0
for x in map(len,input().split('*')):
    i+=x//2;j+=x%2
m=min(b,i)+min(c,i)
print(m+min(b+c-m,j))