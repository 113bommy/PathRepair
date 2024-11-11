n = int(input())

a = input().split()
print(1/sum(map(lambda x:1/int(x), a)))