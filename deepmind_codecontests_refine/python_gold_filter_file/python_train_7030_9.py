s=str(input())
l,n=list(s),len(s)
for i in range(1,n-1):
    if l[i-1]==l[i]:
        if l[i-1]!="z" and l[i+1]!="z":
            l[i]="z"
        elif l[i-1]!="y" and l[i+1]!="y":
            l[i]="y"
        elif l[i-1]!="x" and l[i+1]!="x":
            l[i]="x"
        elif l[i-1]!="u" and l[i+1]!="u":
            l[i]="u"
if n>=2:
    if l[-1]==l[-2]:
        if l[-1]=="z":
            l[-1]="y"
        else:
            l[-1]="z"
print("".join(l))


            