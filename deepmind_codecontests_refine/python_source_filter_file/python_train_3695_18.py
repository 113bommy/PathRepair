
n=int(input())
a=str(input())
n1=a.count("1")
n2=a.count("2")
if a.count("10")>0 or a.count("01")>0:
    print(abs(n1-n2))
else:
    print(n)
