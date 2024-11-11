N=int(input())
S=input()
if len(S)>=N:
    print(S[0:N]+"...")
else:
    print(S)