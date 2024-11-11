M = int(input())
Keta=0
Sum=0

for _ in range(M):
    d,c = map(int,input().split())
    Keta+=c
    Sum+=d*c
print(Keta-1 + (Sum-1)//9)
