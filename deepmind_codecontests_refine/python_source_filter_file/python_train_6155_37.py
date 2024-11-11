n=int(input())
a,b=map(int,input().split())
if max(a-n,b-n)<max(a-1,b-1) :
    print("Black")
else:
    print("White")