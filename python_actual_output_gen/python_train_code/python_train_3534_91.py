k=int(input())
a,b=map(int,input().split())
print('OK' if b//k-a//k>=1 or a%k==0 else 'NO')