K=int(input().split())
A,B=map(int,input().split())
n=A//K
print("OK" if A<=K*n<=B or K*(n+1)<=B else "NG")