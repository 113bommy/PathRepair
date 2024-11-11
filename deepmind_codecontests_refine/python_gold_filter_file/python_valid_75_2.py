# cook your dish here
for _ in range(int(input())):
    n=int(input()) 
    temp=[]
    l=[]
    for _ in range(n):
        temp=[i for i in map(int,input().split())]
        mn=0
        for i in range(1,len(temp)):
            mn=max(mn,temp[i]+1-(i-1))
        l.append([mn,temp[0]])
    l.sort(reverse=True) 
    posbl=0 
    for i in range(len(l)):
        if posbl<l[i][0]:
            posbl=l[i][0]
        if i+1!=len(l):
            posbl-=l[i+1][1] 
    print(posbl)
            
    