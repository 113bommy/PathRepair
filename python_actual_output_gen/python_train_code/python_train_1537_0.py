k=int(input())
inp=[int(j) for j in input().split()]

flag=0
lis=[]
for j in range(k):
    mini=min(inp[j:])
    ind=inp.index(mini)
    if inp[j]!=inp[ind]:
        inp[j],inp[ind]=inp[ind],inp[j]
        lis.append([j,ind])
        
if len(lis)==0:
    print("0")
else:
    print(len(lis))
    for i in range(len(lis)):
        print(lis[i][0],lis[i][1])
    
    