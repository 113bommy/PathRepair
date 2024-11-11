import math
def solve(n):
  count = 0
  arr = []
  for i in range(1,n+1):
    k = ['.']*n
    if i %2 == 0:
      for c in range(0,n,2):
        k[c] = 'C'
        count += 1
    else:
      for c in range(1,n,2):
        k[c] = 'C'
        count += 1

    arr.append(''.join(k))
  print(count)
  for i in arr:
    print(i, end='\n')
    
def main():
  #arr1 =list(map(int,input().split(' ')))
  #arr1 =input().split(' ')
  #arr2 = []
  n = int(input())
  #for j in range(n):
    #i = input()
    # i = input().split(' ')
    #i = int(''.join(input().split(' ')))
    #arr2 = arr2 + i
  #n = input()
  #t = input()
  solve(n)

main()