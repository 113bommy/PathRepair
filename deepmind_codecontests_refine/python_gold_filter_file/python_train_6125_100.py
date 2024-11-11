A,B,C,D=map(int,input().split())
print(["Balanced","Left","Right"][(C+D<A+B)-(C+D>A+B)])