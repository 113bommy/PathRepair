import sys

l=sys.stdin.readline().split()

n = int(l[0])
a = int(l[1]) #arthur
b = int(l[2]) #alexander
answer = ""
arthur =sorted(list( map(int, sys.stdin.readline().split())))
alexander =sorted(list( map(int, sys.stdin.readline().split())))
vector = [2 for i in range(n)]
for i in range(a):
    if (i+1) == arthur[i]:
        vector[i]=1

for e in vector:
    answer = answer + str(e) + " "
print(answer)