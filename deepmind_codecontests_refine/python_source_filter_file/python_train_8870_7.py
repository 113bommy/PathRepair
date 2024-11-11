n,a,b,k = map(int,input().split())
H = list(map(int,input().split()))

gain = 0
H = [hp % (a+b) for hp in H]
H = [(a+b) if hp == 0 else hp for hp in H]
H.sort()
for hp in H:
  if hp <= a:
    gain += 1
  else:
    if hp - a <= k*a:
      gain += 1
      k -= hp//a
    
print(gain)