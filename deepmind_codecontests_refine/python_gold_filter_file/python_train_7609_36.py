n=int(input())
z=list(map(int,input().split()))
print(max(z)-(min(z)+n-1))