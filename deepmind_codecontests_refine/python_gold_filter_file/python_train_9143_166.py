A,B,C,D = map(int,input().rstrip().split(" "))
print(max(min(B,D) - max(A,C),0))