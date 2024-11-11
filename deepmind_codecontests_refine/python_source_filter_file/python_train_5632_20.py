import math
def main():
  [n,m]=map(int,input().split(" "))
  if n>m:
    print(0)
  else:
    food = [int(x) for x in input().split(" ")]
    inventory = [food.count(x) for x in list(set(food))]
    print(inventory)
    burst = sum([1-(1/x) for x in inventory])
    a = math.floor(m/(n+len(inventory)))
    print(a)
    while sum([math.floor(x/a) for x in inventory]) >= n:
      a += 1
    print(a-1)

main()