n=int(input())
s=sorted(input())
t=s[::n]*n
if sorted(t)==s:
    "".join(t)
else:
    print("-1")






