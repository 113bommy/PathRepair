N = int(input())
list=set()
for i in range(N):
    list ^= {int(input())}
print(len(list))