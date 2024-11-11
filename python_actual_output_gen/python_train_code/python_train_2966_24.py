N,K=map(int, input().split())
List=list(map(int,input().split())) 
print(sum(1 for x in List if x>K))