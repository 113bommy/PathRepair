n=int(input())
inp = list(map(int,input().split()))
k=inp[0]
count=0
maxi=0
for i in range(0,len(inp)):
    if(k<=inp[i]):
        count+=1
        k=inp[i]
        if(maxi<count):
            maxi=count
    else:
        k=inp[1]
        count=1
print (maxi)
        
    