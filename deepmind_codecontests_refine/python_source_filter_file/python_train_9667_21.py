h,w = map(int,input().split())
c = 0
for i in range(h):
    c += list(input()).count('#')
if c == h+w-1:
    print('Possible')
else:
    print('Imipossible')
