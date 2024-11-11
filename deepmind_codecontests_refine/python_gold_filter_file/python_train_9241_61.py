k=int(input())
w=input()
if len(w)<=k:
    print(w)
else:
    print(w[:k]+"...")
