def k_string(n,k):
  string=['a' for i in range(n)]
  first=1
  while k>first*(first-1)/2:
    first+=1
  second=k-first*(first-1)//2
  string[-(first-1)]='b'
  string[-second]='b'
  return(string)


def test():
  number_of_tests=int(input())
  for i in range(number_of_tests):
    nk=input().split(" ")
    n=int(nk[0])
    k=int(nk[1])
    output="".join(k_string(n,k))
    print(output)
  return()

test()