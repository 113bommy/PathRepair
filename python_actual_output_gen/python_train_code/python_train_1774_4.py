# cook your dish here
t=input()
t=int(t)
while t!=0:
    n=input()
    n=int(n)
    s=input()
    l=[]
    for i in range(n):
        if s[i]=='A':
            l.append(i)
    max=-1
    for i in l:
        c=0
        index=i
        while index+1<n and s[index+1]=='P':
            c=c+1
            index=index+1
        if max<c:
            max=c
    print(max)
    t=t-1