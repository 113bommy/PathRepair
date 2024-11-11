n,a,b,c,d=map(int,input().split())
s=input()
if s[a-1:max(c,d)].count("##")>0:
    print("No")
elif c<d:
    print("Yes")
else:
    if s[b-2:d:].count("...")==0:
        print("No")
    else:
        print("Yes")
