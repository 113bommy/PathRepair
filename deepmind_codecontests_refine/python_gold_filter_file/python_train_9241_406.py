n=int(input())
S=input()
if len(S)>n:
    print(S[:n]+"...")
else:
    print(S)