A, B, C, D = map( int, input().split())
L = A + B
R = C + D
print(["Balanced","Left","Right"][R<L - R>L])