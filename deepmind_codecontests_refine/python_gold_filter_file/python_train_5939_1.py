import statistics
data=[]
while True:
    n=eval(input())
    if n==0:break
    data.append(list(map(int,input().split())))
Data=iter(data)
for i in Data:
        print(statistics.pstdev(i))