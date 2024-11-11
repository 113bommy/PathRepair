def main():
  n,*a=map(int,open(0).read().split())
  c=0
  for i in range(61):
    i=2**i
    t=sum(i&b and 1for b in a)
    c=(c+t*(n-t)*i)%(10**9+7)
  print(c)
main()