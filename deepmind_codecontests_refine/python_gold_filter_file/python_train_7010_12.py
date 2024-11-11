def main():
    mode="filee"
    if mode=="file":f=open("test.txt","r")
    get = lambda :[int(x) for x in (f.readline() if mode=="file" else input()).split()]
    [n,m]=get()
    if n==0 and m>0:
        print("Impossible")
        return
    print(n+max(0,m-n),n+max(0,m-1))
    


    if mode=="file":f.close()


if __name__=="__main__":
    main()
