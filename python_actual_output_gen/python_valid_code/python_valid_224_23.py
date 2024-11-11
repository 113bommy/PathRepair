A,B,C,D,E,F=map(int,input().split())
maxim=0
ans=[0,0]
for i in range(F//100//A+1):
  for j in range(F//100//B+1):
    if A*100*i+B*100*j >= F:
      break
    for k in range(F//C+1):
      if A*100*i+B*100*j+C*k >= F:
        break
      for l in range(F//D+1):
        s=D*l+C*k
        w=A*100*i+B*100*j
        if s+w<=F:
          if w//100*E>=s:
            if s!=0:
              if maxim<=100*s/(s+w):
                maxim=100*s/(s+w)
                ans=[w+s,s]
print(*ans)