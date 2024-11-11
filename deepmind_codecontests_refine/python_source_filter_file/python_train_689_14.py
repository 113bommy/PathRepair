n,d = list(map(int, input().split()))
p = list(map(int, input().split()))

# p.sort()
m = max(p)
A = [0] * m

for pp in p:
  A[pp-1] = A[pp-1] + 1

# print(A)

minr = 1001
for i in range(m-d):
  # print(A[i:i+d+1])
  x = sum(A[i:i+d+1])
  if minr > (n-x):
    minr = n-x

print(minr)

# def dis(p):
#   return abs(p[0] - p[len(p)-1])


# # print(dis([1]))

# for i in range(len(p)):
#   # print(p[i:], p[:len(p)-i])
#   # print(dis(p[i:]), dis(p[:len(p)-i]))

#   d1 = dis(p[i:])
#   d2 = dis(p[:len(p)-i])

#   if d1 <= d or d2 <=d:
#     print(i)
#     break
