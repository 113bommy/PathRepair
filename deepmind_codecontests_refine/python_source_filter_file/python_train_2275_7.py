n = int(input())
a = [int(i) for i in input().split()]

ans = 'Yes'
if sum(a)%2 != 0:
  ans = 'No'
  
print(ans)