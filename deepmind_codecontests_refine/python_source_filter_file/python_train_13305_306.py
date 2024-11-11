A, B = map(int,input().split())
ans = A+B if A % B == 0 else B-A
print(ans)