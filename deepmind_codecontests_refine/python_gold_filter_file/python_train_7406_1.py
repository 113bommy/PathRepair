input()
x=2*list(map(int,input().split()))+[0,0,0]
days=0
i=0
D=[]

if 1 not in x:
    print(0)
    exit(0)
while i<len(x):
    days=0
    if x[i]:
        days=0
        while x[i+1]:
            days+=1
            i+=1
        D.append(days)
        i+=1
    else:
        i+=1
    
print(max(D)+1)
