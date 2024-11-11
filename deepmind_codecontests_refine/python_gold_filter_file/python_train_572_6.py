a,b,c=map(int,input().split())
for i in range(c//a+1):
    if (c-i*a)%b==0: print('Yes'); break
else: print('No')