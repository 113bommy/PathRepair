[N,M]=list(map(int,input().split()))
A=list(map(int,input().split()))
print(["No","Yes"][int(len (list(filter(lambda Ai:Ai>sum(A)/4/M,A)))>M-1)])