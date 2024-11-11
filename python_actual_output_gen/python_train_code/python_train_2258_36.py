n=int(input())
x=['a','b','c']
for i in range(n):
    print(x[i%3],end='')