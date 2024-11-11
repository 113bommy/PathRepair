n,a,b,c,d=map(int,input().split())
s=input()
if d>c:
    if "##" in s[b-1:d] or "##" in s[a-1:c]:
        print("No")
    else:
        print("Yes")
elif c>d:
    if ("##" not in s[a-1:c]) and ("..." in s[a-1:c]):
        print("Yes")
    else:
        print("No")