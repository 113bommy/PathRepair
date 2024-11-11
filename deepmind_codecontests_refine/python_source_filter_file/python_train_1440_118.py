N,X = map(int, input().split())
li = [int(input()) for i in range(N)]

print(N+(sum(li)//min(li)))
