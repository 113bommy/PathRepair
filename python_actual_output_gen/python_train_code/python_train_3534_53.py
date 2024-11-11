K=int(input())
A,B = map(int,input().split())
print("OK" if B-A+1>=K else "NG")