n = int(input())
l = []
while(n):
    l.append(n % 10);
    n = n // 10

while(len(l) < 5):
    l.append(0)
n = l[4]*10000 + l[3] + l[2]*1000 + l[1]*10 + l[0]*100
x = pow(n, 5)
l2=[]
while(x):
    l2.append(x % 10);
    x = x // 10

while(len(l2) < 5):
    l2.append(0)
l3=[]
for i in range(5):
    l3.append(l2[i])
l3.reverse()

for i in l3:
    print(i)