,w=input().split()
a=[list(input()) for i in range(int(h))]

l1=[i for i in a if '#' in i]
l2=[i for i in zip(*l1) if '#' in i]
for i in zip(*l2):
    print(''.join(i))