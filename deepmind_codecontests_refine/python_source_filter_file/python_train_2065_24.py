input()
a=list(map(int,input().split()))
count=0

while all(a%2 == 0 for i in a):
    i=[i/2 for i in a]
    count+=1
print(count)