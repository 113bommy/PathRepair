A,B = map(int, input().split())
print(max(A+B,A+A-1,B+B-1))