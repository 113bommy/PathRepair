from collections import Counter
import io
import os
input=io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
def main():
  for t in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    ma=0
    b=Counter()
    for i in range(n):
      b[a[i]]+=1
    for i in range(2,2*max(a)+1):
      c=Counter()
      p=0
      for j in range(n):
        if i-a[j]>0:
          if i-a[j]!=a[j]:
            if b[i-a[j]]>c[i-a[j]] and b[a[j]]>c[a[j]]:
              c[a[j]]+=1
              c[i-a[j]]+=1
              p+=1
          else:
            if b[a[j]]-c[a[j]]>=2:
              p+=1
              c[a[j]]+=2
      ma=max(ma,p)
    print(ma)
if __name__=="__main":
  main()