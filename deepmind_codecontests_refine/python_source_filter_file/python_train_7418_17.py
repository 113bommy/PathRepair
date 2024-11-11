def solve():
  x = int(input())
  dif = x-30
  nums=[6,10,14]
  if x>30:
    if (dif==6):
      nums=[5,10,15,6]
    if (dif==10):
      nums=[6,14,15,5]
    if (dif==14):
      nums=[6,14,15,9]
    print("YES")
    print(*nums)
  else:
    print("NO")

def main():
  t = int(input())
  for i in range(t):
    solve()

if __name__ == "__main__":
    main()
