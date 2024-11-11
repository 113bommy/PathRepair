n,a,b,c,d=map(int,input().split())
s=input()
if s[:max(c,d)].count("##")>0:
    print("No")
elif c<d:
    print("Yes")
else:
    if s[b-1:d+2].count("...")>0:
        print("Yes")
    else:
        print("No")
