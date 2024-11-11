k=int(input())
n=input()
if len(n)>k:
    print(n[:k]+"...")
else:
    print(n)