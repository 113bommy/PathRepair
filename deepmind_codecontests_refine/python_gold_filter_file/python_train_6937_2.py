n,pos,l,r=map(int,input().split())
result=0
if pos<=l:
    if l!=1:
        result+=abs(pos-l)+1
    if r!=n:
        result+=abs(r-l)+1
elif pos<=r:
    if l!=1:
        result+=abs(pos-l)+1
    if r!=n:
        result+=abs(pos-r)+1
    if r!=n and l!=1:
        result+=min(abs(pos-l),abs(pos-r))
else:
    result+=abs(r-pos)+1
    if l!=1:
        result+=abs(l-r)+1
print(result)