N=int(input())
x=sorted(list(map(int,input().split())),reverse=True)
print(sum(x[1::2][:N]))