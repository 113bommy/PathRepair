for _ in range(int(input())):
    n = int(input())
    lis = list(map(int,input().split()))
    ans=['2' if i%2 else '1' for i in range(n)]
    aa=2
    if len(set(lis))==1:
      print(1)
      print(1*(n))
    else:
      if n%2==0 or lis[0]==lis[-1]:
        aa=2
      else:
        c=0
        for i in range(1,n):
          if lis[i]==lis[i-1]:
            c=1
            break
        if c==1:
          ans[i:]=ans[i-1:-1]
          ans[-1]=2
        else:
          aa=3
          ans[-1]=3
      print(aa)
      print(*ans)
            
        
        



