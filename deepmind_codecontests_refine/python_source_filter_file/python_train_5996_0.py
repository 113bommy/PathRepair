(n,k)=list(map(int,input().split()))
input2=list(map(int,input().split()))
outputlist=[]
currentl=[i for i in range(0,n)]
ved=1
for i in range(len(input2)):
    number=input2[i]%len(currentl)
    while number>0:
        ved+=1
        ved%=len(currentl)
        number-=1
    outputlist.append(currentl[ved])
    del currentl[ved]
    ved%=len(currentl)
print(' '.join(map(str, outputlist)))