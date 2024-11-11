a,b,c = map(int,input().split())
l = [i for i in range(a,b+1) if c % a ==0]
print(len(l))