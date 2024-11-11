n, a = map(int, input().split())
criminals = [-1] + list(map(int, input().split() )) + [-1]


catch = 0
left = a - 1
right = a + 1
while left > 0 and right < n+1:
  if criminals[left] > 0 and criminals[right] > 0:
    catch = catch + criminals[left] + criminals[right]
    
  left -= 1
  right += 1

if left == 0:
    while right < n:
      catch += criminals[right]
      
      right += 1

if right == n+1:
  while left>0:
    catch += criminals[left]
    
    left-=1
if criminals[a] > 0:
  catch += criminals[a]
print(catch)
