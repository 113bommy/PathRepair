n=int(input())
*A,=map(int,input().split())
*B,=map(int,input().split())
print("Yes" if sum(B)-sum(A) >= sum(max(0,a-b) for a,b in zip(A,B)) else "No")