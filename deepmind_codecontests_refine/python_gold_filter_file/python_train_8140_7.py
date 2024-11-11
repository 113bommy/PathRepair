for _ in range(int(input())):
    s=input().strip()
    cnt=0
    res=[i+2 for i in range(len(s)) if s.startswith("twone",i)]

    cnt+=len(res)
    s=s.replace("twone","tw1ne")
    res1=[m+1 for m in range(len(s)) if s.startswith("one",m)]
    res.extend(res1)
    x=len(res1)
    s=s.replace("one","o1e")
    res2=[b+1 for b in range(len(s)) if s.startswith("two",b)]
    y=len(res2)
    res.extend(res2)
    cnt+=x+y
    print(cnt)
    s=""
    for i in range(len(res)):
        res[i]+=1
        s+=str(res[i])+" "
    print(s)