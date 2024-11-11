# # RED CODER # #
n = int(input())
x = list(map(int, input().split()))[:n]
x = [int(i) for i in x if i!=0]
print(x)
print(len(set(x)))
