n=int(input())
print(['aabb'*(n//4)+'aabb'[:n%4],'a'*n][n<3])