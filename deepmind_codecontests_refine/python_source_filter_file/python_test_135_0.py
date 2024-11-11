import sys
def get_ints(): return map(int, sys.stdin.readline().strip().split())
def get_list(): return list(map(int, sys.stdin.readline().strip().split()))
def get_string(): return sys.stdin.readline().strip()
def get_int(): return int(sys.stdin.readline().strip())
def get_list_strings(): return list(map(str, sys.stdin.readline().strip().split()))


# Output for list
# sys.stdout.write(" ".join(map(str, final)) + "\n")

# Output for int or str
# sys.stdout.write(str(best) + "\n")



def solve():
  n, k = get_ints()
  arr = get_list()

  if k == 0:
    print(sum(arr))
    return

  arr.sort()
  ans = 0

  for i in range(n-2*k):
    ans += arr[i]
  
  final = []

  for i in range(n-2*k, n):
    final.append(arr[i])
  
  store = {}

  for ele in final:
    if ele not in store:
      store[ele] = 1
    else:
      store[ele] += 1
  
  req = []
  for ele in store:
    req.append(store[ele])
  
  req.sort()
  last = req[-1]
  length = len(req)

  temp = 2*last - length

  if temp <= 0:
    print(ans)
    return
  
  ans += temp//2

  print(ans)

    

  




















T = get_int()
while T:
  solve()
  T -= 1
