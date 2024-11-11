K=int(input())
A,B=map(int,input().split())
print("OK" if B-A>=K-1 else "NG")