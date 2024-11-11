a,b = list(map(int,input().split()))
D = b-a
print(D*(D+1)//2-b)
