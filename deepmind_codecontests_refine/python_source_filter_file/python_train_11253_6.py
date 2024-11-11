def inp1():
    return int(input())
def inp2():
    return list(map(int,input().split()))
def inp3():
    return map(int,input().split())
if 1:
#for _ range(int(input(()))):
    n=inp1()
    x=int(n**0.5)
    i=0
    y=n
    ans=[]
    while(i<n):
          arr=[]
          for j in range(x):
              if y==0:
                  break
              arr.append(y)
              y-=1
              i+=1
              if y==0:
                  break
          arr=arr[::-1]
          for j in arr:
              ans.append(j)
    print(ans)
