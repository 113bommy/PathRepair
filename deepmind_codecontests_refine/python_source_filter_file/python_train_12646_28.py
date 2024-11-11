n=int(input())
s=input()
s.lower()
k=len(set(s))
if(k==26):
    print("YES")
else:
    print("NO")