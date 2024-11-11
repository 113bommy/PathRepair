n = int(input())+1
f = sum(map(int,input().split()))
l = [x for x in range(1,6) if (f+x)%n+1!=1]
print(len(l))