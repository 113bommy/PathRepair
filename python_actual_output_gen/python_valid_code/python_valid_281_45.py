n,m=map(int,input().split())
S=list(map(str,input().split()))
T=list(map(str,input().split()))
q=int(input())
for i in range (q):
    y=int(input())
    print(S[y%n]+T[y%m])