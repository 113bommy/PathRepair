a = int(input())
l = [int(input()) for i in range(a)]
print(sum(l)-max(l)//2)