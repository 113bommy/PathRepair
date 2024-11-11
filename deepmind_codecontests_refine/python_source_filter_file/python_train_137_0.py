n=int(input())
s=sorted(input())
x=s[::n]*2
if sorted(x)==s:
    print("".join(x))
else:
    print(-1)