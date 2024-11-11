p=sorted([int(input()) for _ in range(int(input()))])
print(sum(p[0:-1])+p[-1]//2)