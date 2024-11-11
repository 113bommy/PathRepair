N= int(input())
ts = [int(input()) for i in range(5)]
print(int((N-1)/min(ts)) + 5)