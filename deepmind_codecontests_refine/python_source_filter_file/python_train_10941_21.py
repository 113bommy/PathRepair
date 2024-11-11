def missing(string):
    if 'A' not in string:
        return 1
    elif 'B' not in string:
        return 2
    else:
        return 3

def letter(x):
    if x==1:
        return 'A'
    elif x==2:
        return 'B'
    else:
        return 'C'

n=int(input())
arr=[]
for _ in range(n):
    x, y = input().split()
    item=[int(x),str(y)]
    arr.append(item)

arr.sort()
len3=100000000000


found=0
statA=0
statB=0
statC=0
for _ in range(n):
    if len(arr[_][1])==3:
        #print(arr[_])
        found=1
        len3=arr[_][0]
        statA=1
        statB=1
        statc=1
        break

MisLetter=0
len2=100000000000
tempStat=0
for _ in range(n):
    if len(arr[_][1])==2:
        MisLetter=missing(arr[_][1])
        len2=arr[_][0]
        #print(arr[_][1])
        
        for i in range(n):
            if letter(MisLetter) in arr[i][1]:
                #print(arr[_][1],arr[i][1])
                tempStat=1
                len2+=arr[i][0]
                found=1
               # print(len2)
                statA=1
                statB=1
                statC=1
                break
                
        if tempStat==1:
            
            break

if tempStat==0:
    len2=100000000000
len1=0
statAA=0
statBB=0
statCC=0
for _ in range(n):
    if arr[_][1]=='A':
        statAA=1
        len1+=arr[_][0]
        break
for _ in range(n):
    if arr[_][1]=='B':
        statBB=1
        len1+=arr[_][0]
        break
for _ in range(n):
    if arr[_][1]=='C':
        statCC=1
        len1+=arr[_][0]
        found=1
        if statAA==1:
            
            statA=1
        if statBB==1:
            
            statB=1
        
        statC=1
       
        break
if statAA!=1 or statBB!=1 or statCC!=1:
    len1=10000000000000
if found==0:
    print(-1)
else:
    if statA==0 or statB==0 or statC==0:
        print(-1)
    else:
        
        print(min(len3,len2,len1))
        
