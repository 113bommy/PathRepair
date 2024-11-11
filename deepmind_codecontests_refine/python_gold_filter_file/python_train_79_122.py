A,B = map(int,input().split())
print(A*B if max(A,B)<10 else -1)