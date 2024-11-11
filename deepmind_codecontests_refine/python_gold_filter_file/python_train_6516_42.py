n=int(input())
x=['a','a','b','b']
for i in range(n):
    print(x[i%4],end='')