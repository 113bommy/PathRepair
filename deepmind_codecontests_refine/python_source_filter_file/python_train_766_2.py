#             _______   ________       ________   ________   ________
# |        | |       | |        |  |  |          |          |        |
# |        | |       | |        |  |  |          |          |        |
# |        | |_______| |________|  |  |________  |________  |________|
# |        | |         |\__        |          |  |          |\__
# |        | |         |   \__     |          |  |          |   \__
# |________| |         |      \__  |  ________|  |________  |      \__

x=int(input())
A=input().split()
p=[]
n=[]
z=[]
for i in A:
    k=int(i)
    if k<0: n.append(k)
    elif k>0: p.append(k)
    else: z.append(k)

if (len(p) == 0):
        p.append(n[0])
        p.append(n[1])
        del n[0:2]

if(len(n)%2==0):
    z.append(n[0])
    n.pop(0)

print(len(n),end=' ')
for i in n:
    print(int(i),end=' ')
print()

print(len(p),end=' ')
for i in p:
    print(int(i),end=' ')
print()

print(len(n),end=' ')
for i in z:
    print(int(i),end=' ')
