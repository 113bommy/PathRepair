H, W = map(int, input().split())

s = ['.'*(W+2)] + ['.'+input()+'.' for _ in range(H)] + ['.'*(W+2)]
for hi in range(1, W+1):
  for wi in range(1, H+1):
    if s[hi][wi] == '.':
      continue
    if s[hi-1][wi]=='.' and s[hi+1][wi]=='.':
      if s[hi][wi-1]=='.' and s[hi][wi+1]=='.':
        print('No')
        exit()
        
print('Yes')