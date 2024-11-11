stones={'purple':'Power','green':'Time','blue':'Space','orange':'Soul','red':'Reality','yellow':'Mind'}
s=set()
t=int(input())
for i in range(t):
    inp = input()
    s.add(inp)
print(6-t)
for (key,value) in stones.items():
    if key not in s:
        print(value)