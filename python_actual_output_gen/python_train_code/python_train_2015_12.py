c=list(input())
s=""
for x in c:
    if x!=B:
        s+=x
    else:
        s=s[:-1]
print(s)