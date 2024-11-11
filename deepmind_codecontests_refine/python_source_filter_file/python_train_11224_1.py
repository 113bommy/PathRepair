N = int(input())
A = [int(i) for i in input().split()] + [1]

# 一個前の提出は嘘解法だったてへぺろ
# 桁上げの処理はpopのときにまとめてやれば良い
def check(m) :
  rl = [[0, A[0]]]
  for i in range(1, N + 1) :
    if A[i-1] < A[i] :
      rl.append([0, A[i] - A[i-1]])

    else :
      cnt = A[i-1]
      while A[i] <= cnt :
        char, size = rl.pop()
        cnt -= size
        if char >= m and size > 1 :
          if size > 2 :
            rl.append([char, size - 2])
            cnt += size - 2
          rl.append([char + char // m, 1])
          cnt += 1
        elif char >= m and size == 1 :
          if len(rl) == 0 : 
            return False
          c, s = rl.pop()
          if s > 1 :
            rl.append([c, s - 1])
          rl.append([c + char // m, 1])
        
      if A[i] - cnt - 1 >= 1 :
        rl.append([char % m, A[i] - cnt - 1])
      rl.append([char % m + 1, 1])
      cnt = A[i]
  return True

if all(A[i-1] <= A[i]for i in range(1, N)) :
  print(1)

else :
  ng, ok = 1, N
  while ok - ng > 1 :
    m = (ok + ng) // 2
    
    if check(m) :
      ok = m
    else :
      ng = m
      
  print(ok)