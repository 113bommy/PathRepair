a,b,c,d=map(int,input().split())
print(["Balanced","Left","Right"][(a+b<c+d)*2+(a+b>c+d)])