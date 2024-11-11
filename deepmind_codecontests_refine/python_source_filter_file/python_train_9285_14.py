n = int(input())
r = list(map(int, input().split()))
print (sum(r[:n//2])**2+(sum(r)-sum(r[:n//2]))**2)