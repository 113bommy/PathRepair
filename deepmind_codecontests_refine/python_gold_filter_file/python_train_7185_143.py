

[a,b,c] = map(int,input().split())

print({True: 'Yes', False: 'No'}[a < b < c])
  