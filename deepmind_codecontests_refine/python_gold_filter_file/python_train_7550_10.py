n=int(input())
s=input()
sl=len(set(s))
if(n>26):
    print("-1")
else:
    print(n-sl)