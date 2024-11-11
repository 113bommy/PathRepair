A,B = map(int,input().split())
print(max(A+A-1,A+B-1,B+B-1))
