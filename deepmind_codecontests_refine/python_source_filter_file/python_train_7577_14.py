def main():
  import math
  import sys
  imput=sys.stdin.readline
  a=int(input())
  b=input()
  R=0
  L=0
  ans=1
  mod=10**9+7
  if b[0]=="W" or b[-1]=="W":
    print(0)
    exit()
  for i in range(2*a):
    if i==0:
      L+=1
      fr="L"
    else:
      if b[i]==b[i-1]:
        if fr=="L":
          ans=ans*(L-R)
          R+=1
          fr="R"
        else:
          L+=1
          fr="L"
      else:
        if fr=="L":
          L+=1
        else:
          ans=ans*(L-R)
          R+=1
    
  if L!=R:
    print(0)
    exit()


  
  print(ans*math.factorial(a)%mod)
  

if __name__ == '__main__':  
  main()
  