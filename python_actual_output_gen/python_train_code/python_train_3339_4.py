N = int(input())
list={}
for i in range(N):
    list ^= {int(input())}
print(len(list))