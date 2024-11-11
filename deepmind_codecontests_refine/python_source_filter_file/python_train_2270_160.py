A,B=map(int,input().split())
C=input()
print(C[:B]+C[B].lower()+C[B+1:])