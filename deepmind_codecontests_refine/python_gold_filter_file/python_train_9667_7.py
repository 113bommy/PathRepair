h,w=map(int,input().split())
c=0
for _ in range(h):
  c+=input().count('#')
print('Possible' if c==h+w-1 else 'Impossible')