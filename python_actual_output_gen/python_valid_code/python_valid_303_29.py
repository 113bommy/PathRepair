n=int(input())
ans=n//111*(n+1)
print(ans if ans>n else ans-111 )