n=int(input())
l=[int(x) for x in input().split()]
l2=l[1:]
a=list(zip(l,l2))
a=[sorted(i) for i in a]
print(a)
for i,j in a:
    for c,d in a:
        if c>i and c<j and d>j:
                print("yes")
                exit()

              
print("no")            
