def main():
    mode="filee"
    if mode=="file":f=open("test.txt","r")
    #f.readline()
    #input()
    get = lambda :[int(x) for x in (f.readline() if mode=="file" else input()).split()]
    [k]=get()
    b=[False]*26
    q = input()
    if k>len(q):
        print("NO")
        return
    if k==1:
        print("YES")
        print(q)
        return
    done=[]
    i=-1
    last=0
    b[ord(q[0])-97]=True
    while i<len(q)-1 and k>0:
        i+=1
        if b[ord(q[i])-97]:
            continue
        done.append(q[last:i])
        b[ord(q[i])-97]=True
        last=i
        k-=1
    if k==0:done[-1]+=q[last:]
    else:
        done.append(q[last:])
        k-=1
    if k>0:
        print("NO")
    else:
        print("YES")
        for i in done:
            print(i)

    if mode=="file":f.close()


if __name__=="__main__":
    main()
