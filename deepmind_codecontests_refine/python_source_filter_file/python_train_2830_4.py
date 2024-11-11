n=int(input())
s=input()
s1=[]
for i in s:
    s1.append(i)
t=input()
t1=[]
for i in t:
    t1.append(i)
    
sa = s.count("a")
ta = t.count("a")
if (sa+ta)%2!=0 or (2*n-sa-ta)%2!=0:
    print(-1)
else:
    ans=[]
    y=[]
    i=0
    k=0
    while i<n:
        if t1[i]!=s1[i]:
            y.append([s1[i],t1[i],k+1])
        i+=1
        k+=1
    y=sorted(y)

    if len(y)==0:
        print(0)
    else:
        
        i=1
        while i<n:
            if y[i][0]!=y[i-1][0]:
                break
            i+=1
        
        if i%2==0:
            i=1
            while i<len(y):
                ans.append([y[i-1][2],y[i][2]])
                i+=2
            print(len(ans))
            for i in ans:
                print(i[0],i[1])
        else:
            i=3
            while i<len(y)-1:
                ans.append([y[i-1][2],y[i][2]])
                i+=2
            ans.append([y[0][2],y[0][2]])
            ans.append([y[0][2],y[-1][2]])
            print(len(ans))
            for i in ans:
                print(i[0],i[1])
       