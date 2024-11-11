n,m=map(int,input().split())
b=[]
for x in range(n):
    b=list(input().split())
if('C' in b or 'M' in b or 'Y' in b):
    print("#color")
    exit()
print("#Black&White")
