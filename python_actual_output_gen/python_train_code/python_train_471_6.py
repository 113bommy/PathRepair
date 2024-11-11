a=[int(input()) for _ in [0]*5]
b=[-(-a//10)*10-i for i in a]
print(sum(b)+sum(a)-max(b))