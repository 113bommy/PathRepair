N = int(input())
li = [int(input()) for i in range(N)]
print(sum(li)-max(li)//2)