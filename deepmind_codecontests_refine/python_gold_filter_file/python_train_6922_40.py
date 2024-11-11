n, m = map(int, input().split())
a_k, b_l =  map(int, input().split())
a =  list(map(int, input().split()))
b =  list(map(int, input().split()))
numbers_a = a[0:a_k]
numbers_b = b[m-b_l:m]
if(min(numbers_b) > max(numbers_a)):
  print('YES')
else:
  print('NO')
