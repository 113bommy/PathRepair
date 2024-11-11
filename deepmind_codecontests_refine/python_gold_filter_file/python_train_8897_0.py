def main():
    mode="filee"
    if mode=="file":f=open("test.txt","r")
    get = lambda :[int(x) for x in (f.readline() if mode=="file" else input()).split()]
    gets = lambda :[str(x) for x in (f.readline()[:-1] if mode=="file" else input()).split(":")]
    [n,m,t]=get()
    a=[0]*20002
    b=[0]*20002
    if n<m:
        print("No solution")
        return
    for i in range(1,1+n):
        g = gets()
        a[i] = int(g[-1]) + int(g[1])*60 + int(g[0])*3600
        [p,count,sim] = [1,0,0]
    is_solution_there=False
    for i in range(1,n+1):
        while p<i and a[i] - t + 1>a[p]:
            p+=1
            if b[p]!=b[p-1]:
                sim = max(sim-1,0)
        if a[i]<a[p]+t and sim<m:
            count+=1
            sim+=1
        if sim==m:
            is_solution_there=True
        b[i] = count
    if is_solution_there==False:
        print("No solution")
        return
    print(count)
    for i in range(1,n+1):
        print(b[i],end=' ')

    if mode=="file":f.close()


if __name__=="__main__":
    main()

