def conv(a,x):
    h = 1
    ans=0
    a.reverse()
    for i in a:
        ans+= h*i
        h = h**x
    return ans

def main():
    mode="filee"
    if mode=="file":f=open("test.txt","r")
    get = lambda :[int(x) for x in (f.readline() if mode=="file" else input()).split()]
    [n,x]=get()
    a = get()
    [m,y] = get()
    b = get()
    a=conv(a,x)
    b = conv(b,y)
    if a == b:
        print("=")
    elif a<b:
        print("<")
    else:
        print(">")
    


    if mode=="file":f.close()


if __name__=="__main__":
    main()
