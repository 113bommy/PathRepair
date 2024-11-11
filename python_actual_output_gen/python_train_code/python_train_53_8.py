n=input()
n=sorted(n)
if(len(n)==1):
    print(n)
else:
    for i in n[:-1]:
        if i!="+":
            print(i,end="+")
    print(n[-1])



