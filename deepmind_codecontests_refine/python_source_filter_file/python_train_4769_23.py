# import numpy as np
# from collections import defaultdict
# from functools import reduce

import heapq

# s = input()
Q = int(input())
# A = list(map(int, input().split()))
# n, m, k = map(int, input().split())


A_left_sum = 0
A_left = []
A_right_sum = 0
A_right = []
A_med = None
query_size = 0
b_sum = 0

# n = len(As)
# n is odd:
# A_left + As[n//2] + B_left
# n is even:
# A_left + B_left

for i in range(Q):
    query = list(map(int, input().split()))

    if query[0] == 1:
      a =  query[1]
      if A_med is None:
        A_med = a
      else:
        if query_size%2 == 0: # even
          left_max = -A_left[0]
          right_min = A_right[0]
          if a < left_max:
            heapq.heappushpop(A_left, a)
            A_left_sum += a - left_max
            A_med = left_max
          elif a > right_min:
            heapq.heappushpop(A_right, a)
            A_right_sum += a - right_min
            A_med = right_min
          else:
            A_med = a
        else: # odd
          if A_med <= a:
            heapq.heappush(A_left, -A_med)
            heapq.heappush(A_right, a)
            A_left_sum += A_med
            A_right_sum += a
          else:
            heapq.heappush(A_left, -a)
            heapq.heappush(A_right, A_med)
            A_right_sum += A_med
            A_left_sum += a

      # print(As)
      # print(A_left)
      # print(A_right)
      query_size += 1

      b_sum += query[2]
    else:
      if query_size%2 == 0: #even
        print(-A_left[0], A_right_sum - A_left_sum + b_sum)
      else:
        print(A_med, A_right_sum - A_left_sum + b_sum)
