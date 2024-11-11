A,B,C,D=map(int,input().split())
e=A+B-C-D
print("Balanced")if e==0 else print(["Left","0","Right"][int(e/abs(e))])