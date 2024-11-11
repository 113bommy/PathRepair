n=list(map(int,list(input())))
output=0
while len(n)>0 and n[-1]==9:
    output+=9
    del(n[-1])
if len(n)>=2:
    output=n[0]-1+n[-1]+10
    n.remove(n[0])
    n.remove(n[-1])
    for i in n:
        output+=(i+9)
    print(output)
else:
    output+=sum(n)
    print(output)