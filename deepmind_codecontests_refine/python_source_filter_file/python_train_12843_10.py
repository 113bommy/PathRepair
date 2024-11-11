x,y=map(int,input().strip().split())
l=list(map(str,input().strip().split()))
n=0
for i in l:
    count=0
    for j in i:
        if(j!="4" or j!="7"):
            count+=1
    if(count<=y):
        n+=1
print(n)
            