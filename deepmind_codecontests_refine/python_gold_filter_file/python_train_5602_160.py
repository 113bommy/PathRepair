A,B = map(int,input().split())

print(max(A+A-1,max(A+B,B+B-1)))