t=int(input())
for i in range(t):
    n=(input())
    l=[]
    for i in range(len(n)):
        if(i%2==0):
            l.append(n[i])
    l.append(n[-1])
    for i in l:
        print(i,end="")
        