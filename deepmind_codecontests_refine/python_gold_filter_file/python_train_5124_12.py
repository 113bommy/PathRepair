for _ in range(int(input())):
    n=int(input())
    l=input()
    t=[]
    for i in range(n):
        if l[i]=="A":
            t.append(i)
    t.append(n)
    m=0
    # print(t)
    for i in range(1,len(t)):
        m=max(m,t[i]-t[i-1]-1)
    print(m)
        