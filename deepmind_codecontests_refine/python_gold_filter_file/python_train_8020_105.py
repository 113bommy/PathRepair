a,b=map(int,input().split())
s=""
if a>b:
    s=">"
elif a<b:
    s="<"
else:
    s="=="
print("a",s,"b")