K, A, B = map(int, input().split())
if A <= B :
   print ('-1')
elif K < A:
   print ('1')
else :
   delta = A - B
   ans = (K - A + delta - 1) // delta * 2 + 1
   print ('%ld' % ans)
