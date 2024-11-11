a,b,c = list(map(int,input().rstrip().split()))
if c==0:
    if a==b:
        print("YES")
    else:
        print("NO")
else:
    if (b-a)%c==0 and b-a>0 and c>0:
        print("YES")
    elif (b-a)%c==0 and b-a<0 and c<0:
        print("YES")
    else:
        print("NO")