def solve(data):
  n , m = data
  hash = "#"*(m)
  empty = '.'*(m-1)
  isRight=True
  for i in range(n):
      if i%2 == 0:
           print(hash)
           
      else:
         if isRight:
            print("#"+empty)
         else:
            print(empty+"#")
         isRight = not isRight
         


if __name__ == "__main__":
   solve(list(map(int,input().split(" "))))