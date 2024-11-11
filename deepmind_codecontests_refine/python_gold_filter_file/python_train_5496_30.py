M=int(input())

n_digit=0
n_sum=0
for _ in range(M):
  d,c=map(int,input().split())
  n_digit+=c
  n_sum+=d*c
#print(n_digit,n_sum)

print(n_digit-1+(n_sum-1)//9)