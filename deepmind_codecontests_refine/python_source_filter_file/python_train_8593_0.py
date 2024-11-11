from sys import stdout,stdin
d={}
for _ in range(int(input())):
    t=stdin.readline()
    t=str(t)
    s=t[0]
    n=t[2:]
    b="0"*(18-len(n))
    for i in n:
        if i!="\n":
            if int(i)%2==0:
                b+="0"
            else:
                b+="1"
    if s=="+":
        if b in d:
            d[b]+=1
        else:
            d[b]=1
    elif s=="-":
        d[b]-=1
    else:
        if b in d:
            stdout.write(str(d[b]))
            print()
        else:
            print(0)
        