st=input()
n=len(st)
if n<3:
    print(st[0])
else:
    i=n-1
    res=list(st)
    pt=n-1
    while i>-1:
        if res[i]=="0":
            pt=i
            # res.pop(i)
            # break
        i-=1
    res.pop(pt)
    print("".join(res))