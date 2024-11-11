n=int(input())
z=list(map(int,input().split()))

z.sort()

print(z[n//2])