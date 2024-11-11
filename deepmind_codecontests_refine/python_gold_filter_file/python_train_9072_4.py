def ain():
    return map(int,input().split())
def lin():
    return list(ain())

def plist(l):
    for x in l:
        print(x, end= ' ')
    print()

n = int(input())
x = 0
while ( 2*x - 1 ) < n:
    x+=1
print(x)


fl = 0
k = 0
for i in range(x):
    print(i+1,1)
    k+=1
    if k == n:
        break
for i in range(x-1):
    if k == n:
        break
    print(x,i+2)
    k+=1
    

