def main():
    a,b=map(int,input().split())
    l=list(map(int,input().split()))
    s=sum(l);arr=[]
    d=int(s/b);cs=0;ca=0
    flag=1
    if s%b!=0:
        flag=0
    for i in l:
        cs+=i;ca+=1
        if cs==d:
            cs=0
            arr.append(ca)
            ca=0
        elif cs>d or flag==0:
            flag=0;break
    if flag:
        print("Yes")
        str1 = ' '.join(str(i) for i in arr)
        print(str1)
    else:
        print("No")
if __name__=='__main__':
    main()