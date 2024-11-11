n,a,b,c,d = map(int,input().split())
s=input()+"."
if c<d or (c>d and "..." in s[b:d+1]):
    if "##" not in s[b+1:d+1] and "##" not in s[a:c+1]:
        print("Yes")
    else:
        print("No")
else:
    print("No")