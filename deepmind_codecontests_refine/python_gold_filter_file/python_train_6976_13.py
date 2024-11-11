def bubble_sort(a, n):
  for i in range(0,n):
    for j in range(n-1,i,-1):
      if a[j][1] < a[j-1][1]:
        a[j], a[j-1] = a[j-1], a[j]
  return a

def selection_sort(b, n):
  for i in range(0,n):
    minj = i
    for j in range(i, n):
      if b[j][1] < b[minj][1]:
        minj = j
    b[i], b[minj] = b[minj], b[i]
  return b

if __name__ == '__main__':
  n = int(input())
  a = list(map(str, input().split()))
  b = a[:]
  buble = bubble_sort(a,n)
  select = selection_sort(b,n)
  print(" ".join(map(str, buble)))
  print("Stable")
  print(" ".join(map(str, select)))
  if select == buble:
    print("Stable")
  else:
    print("Not stable")
