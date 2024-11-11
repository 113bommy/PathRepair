n = int(input())
Years=list(map(int, input().split(' ')))
a,b=list(map(int, input().split(' ')))
R = b-a
s=0
for i in range(R):
    s+=Years[i]
print(s)