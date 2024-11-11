n=int(input())
s=input()
sl=len(set(s))
if(n>26):
    print("NO")
else:
    print(n-sl)