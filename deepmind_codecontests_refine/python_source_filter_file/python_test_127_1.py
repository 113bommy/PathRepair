t=int(input())
for i in range(t):
    s1=input()
    s2=input()
    s3=sorted(s1)
    n1=s1.count("a")
    n2=s1.count("b")
    n3=s1.count("c")
    if s2=="abc":
        if n1!=0:
            print("".join(["a"*(s1.count("a"))+"c"*(s1.count("c"))+"b"*(s1.count("b"))]+s3[n1+n2+n3+1:]))
        else:
            print("".join(s3))
    else:
        print("".join(s3))