m,n=map(int,input().split())
k,p=map(int,input().split())
l=0
if ((m - p)<2)and((p - m)<=(p+1)*2):
    l+=1
if (n -k<2)and(k - n<=(n+1)*2):
    l+=1
if l<1:
    print('NO')
else:print('YES')    
    