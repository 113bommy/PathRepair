# cook your dish here
for _ in range(int(input())):
    n,k=map(int,input().split())
    l=input()
    s=[]
    for i in range(n):
        s.append(l[i])
    i=0
    count=0
    while i<n:
        if s[i]=='1':
            for j in range(1,k+1):
                if i+j==n:
                    break
                elif s[i+j]=='1':
                    break
                else:
                    s[i+j]='-1'
            i+=j
        else:
            i+=1
    i=n-1
    while i>-1:
        if s[i]=='1':
            for j in range(1,k+1):
                if i-j<0:
                    break
                elif s[i-j]=='1':
                    break
                else:
                    s[i-1]='-1'
            i-=j
        else:
            i-=1
    i=0
    while i<n:
        if s[i]=='0':
            count+=1
            i+=(k+1)
        else:
            i+=1
    print(count)
