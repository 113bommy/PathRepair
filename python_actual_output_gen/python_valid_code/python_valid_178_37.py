n=int(input())
s=str(input())
s=s.lower()
sets=set(s)
if len(set(s))>=26:
    print("YES")
else:
    print("N0")