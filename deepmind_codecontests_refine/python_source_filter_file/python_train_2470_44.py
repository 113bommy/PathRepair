n = int(input())
l = list(map(int, input().split()))

m = sorted(l)
print(m)
if(len(m)%2==0):
    print(m[(len(m)//2)-1])
else:
    print(m[(len(m)-1)//2])
