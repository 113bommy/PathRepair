A,V = map(int,input().split())
B,W= map(int,input().split())
T = int(input()
dist = abs(A-B)
vec = V-W
print('Yes' if vec*T >= dist else 'NO')