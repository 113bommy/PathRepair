A,B,K=map(int,input().split())
List=[]
for i in range (1,100):
    if A%i==0 and B%i==0:
      List.append(i)
print(List[-K])
    