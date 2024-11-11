# https://codeforces.com/problemset/problem/1439/A1



def d(n=4):
  
  def c(n):
    if n==0:
      return [[]]
    r=[]
    for x in c(n-1):
      r += [[0]+x]
      r += [[1]+x]
    return r

  return { tuple(x):sum(x) for x in c(4)}

def xor(a,b):
  return [x[0]^x[1] for x in zip(a,b) ]

p3=[x for x in d() if sum(x)==3]


route={4:1,1:2,2:3,3:0}
def seek(cur):
  s=sum(cur)  
  for p in p3:
    #print(cur,p,xor(p,cur))
    if sum( xor(p,cur) )==route[s]:
      return p
  print("error")

def printa(a):
  for x in a:
    print(  ''.join(map(str,x)))

def f(a):
  result=[]
  for x in range(0,n,2):
    for y in range(0,m,2):
      i = x-1 if x==n-1 else x
      j = y-1 if y==m-1 else y
      #print("->",x,y,i,j)
      #print( a[i][j],a[i][j+1],a[i+1][j],a[i+1][j+1])
      q=((i,j),(i,j+1),(i+1,j),(i+1,j+1))
      cur=[a[x[0]][x[1]] for x in q]
      #print("aa:",aa)
      while True:
        if sum(cur)==0:
          break  
        r=seek(cur)
        #print(r)
        cur=xor(cur,r)
        #print("q:",q)
        for Q,R,C in zip(q,r,cur):
          #print(Q,R,C)
          #rinta(a)
          if R==1:
            #print("xxx:",Q[0]+1,Q[1]+1,C)
            a[Q[0]][Q[1]]=C

        
        #printa(a)
        
        result+=[[(x[0][0]+1,x[0][1]+1) for x in zip(q,r) if x[1]==1]]
  print( len(result))
  for x in result:      
    #print(x)
    line = []
    for i,j in x:
      line+=[i,j]
    print(" ".join(map(str,line)))
  return


for _ in range(int(input())):
  a=[]
  n,m=map(int,input().split())
  for x in range(n):
    a+=[list(map(int,input()))]
  f(a)
