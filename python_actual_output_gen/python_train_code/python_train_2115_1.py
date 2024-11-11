A, B, C, D = map( int, input().split())
L = A + B
R = C + D
print(["Balance","Left","Right"][R<L - R>L])
