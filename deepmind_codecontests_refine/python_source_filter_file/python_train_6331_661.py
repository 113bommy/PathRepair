n = int(input())
a = [int(input()) for i in range(n)]
h = max(a)
print(sum(a)-h+h/2)